/*
Problem : tree의 지름(트리에서 weight들의 합이 가장 큰 두 node 사이의 거리)을 구해라
Input : tree
Output : tree의 지름

Idea
- 임의의 node(1번 node)에서 DFS 방식을 이용해 weight들의 합이 가장 긴 node를 찾는다.
- 찾은 node에서 DFS 방식을 이용해 tree의 지름을 구한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int NodeCount;                                   // node의 개수
bool visited[10001];                             // 각 node의 방문 여부
vector<pair<int, int>> Tree[10001];              // tree
int MaximumWeightSumNode, MaximumWeightSum = 0;    // 임의의 node에서 weight들의 합이 가장 긴 node, tree의 지름

void DFS(int CurrentNode, int CurrentWeightSum)
{
    // 만약 이미 방문한 node라면 탐색하지 않는다.
    if (visited[CurrentNode])
        return;

    // 현재 방문하고 있는 node를 방문 처리
    visited[CurrentNode] = true;

    // 현재까지 탐색한 경로의 weight들의 합이 구해진 tree의 지름보다 크면,
    // MaximumWeightSumNode와 MaximumWeightSum를 update
    if (MaximumWeightSum < CurrentWeightSum)
    {
        MaximumWeightSumNode = CurrentNode;
        MaximumWeightSum = CurrentWeightSum;
    }

    // 연결된 node들을 방문
    int NextNode, NextWeight;
    for (int i = 0; i < Tree[CurrentNode].size(); i++)
    {
        NextNode = Tree[CurrentNode][i].first;
        NextWeight = Tree[CurrentNode][i].second;

        DFS(NextNode, CurrentWeightSum + NextWeight);
    }
}

int main()
{
    int Parent, Child, Weight;

    // node의 개수와 tree 입력
    cin >> NodeCount;
    for (int i = 0; i < NodeCount - 1; i++)
    {
        cin >> Parent >> Child >> Weight;

        Tree[Parent].push_back(make_pair(Child, Weight));
        Tree[Child].push_back(make_pair(Parent, Weight));
    }

    // 임의의 node(1번째 node)에서 시작하는 tree의 지름을 구하고, 끝점 node를 찾기
    DFS(1, 0);

    // 방문 여부를 초기화하고 찾은 끝점 node에서 부터 tree의 지름을 구한다.
    memset(visited, false, sizeof(visited));
    DFS(MaximumWeightSumNode, 0);

    // 결과값 출력
    cout << MaximumWeightSum;

    return 0;
}