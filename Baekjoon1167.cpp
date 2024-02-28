/*
Problem : tree에서 가장 긴 가중치의 합을 구해라.
Input : tree 및 각 edge의 weight
Output : 가장 긴 가중치의 합

Idea
- vector와 pair를 이용해 tree와 edge의 weight를 입력받는다.
- 임의의 node(1번 node)에서 가장 긴 weight들의 합을 가진 node와 weight들의 합을 구한다.
- 구해진 node에서 가장 긴 weight들의 합을 가진 node를 찾고 weight들의 합을 구한다.

* 참고 자료 : https://blog.myungwoo.kr/112
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int NodeCount;                            // tree의 전체 node의 개수
vector<pair<int, int>> Tree[100001];      // tree
                                          // first : 연결된 node
                                          // second : edge의 weight
bool visited[100001];                     // 각 node의 방문 여부
int MaxWeightSumNode, MaxWeightSum = 0;     // 가장 긴 weight들의 합을 가진 node, weight들의 합

void DFS(int CurrentNode, int CurrentLength)
{
    // 이미 방문했다면 탐색하지 않음
    if (visited[CurrentNode])
        return;

    // 현재 node를 방문 처리하고,
    // 가장 긴 weigth들의 합을 가진 node인지 판단하여 update
    visited[CurrentNode] = true;
    if (MaxWeightSum < CurrentLength)
    {
        MaxWeightSumNode = CurrentNode;
        MaxWeightSum = CurrentLength;
    }

    int NextNode, NextNodeLength;        // 현재 node와 연결된 node와 edge의 가중치
    int tmp;

    // 현재 node와 연결된 모든 node를 조사
    for (int i = 0; i < Tree[CurrentNode].size(); i++)
    {
        NextNode = Tree[CurrentNode][i].first;
        NextNodeLength = Tree[CurrentNode][i].second;

        DFS(NextNode, CurrentLength + NextNodeLength);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int InputNodeNumber, InputConnectedNodeNumber, InputWeight;
    int Result = 0, tmp = 0;

    // 전체 node의 개수 입력 및 tree와 edge의 weight 정보 입력
    cin >> NodeCount;
    for (int i = 0; i < NodeCount; i++)
    {
        cin >> InputNodeNumber;

        while (1)
        {
            cin >> InputConnectedNodeNumber;

            // 만약 -1이 입력되면 while문 종료
            if (-1 == InputConnectedNodeNumber)
                break;

            cin >> InputWeight;

            Tree[InputNodeNumber].push_back(make_pair(InputConnectedNodeNumber, InputWeight));
        }
    }

    // 임의의 node(1번 node)에서 가장 긴 weight들의 합을 가진 node와 weight들의 합을 구한다.
    DFS(1, 0);

    // 방문 여부를 초기화하고, 구해진 node에서 가장 긴 weight들의 합을 가진 node와 weight들의 합을 구한다.
    memset(visited, false, sizeof(visited));
    DFS(MaxWeightSumNode, 0);

    // 결과값 출력
    cout << MaxWeightSum;

    return 0;
}