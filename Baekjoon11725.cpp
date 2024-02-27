/*
Problem : 각 node의 parent를 출력해라.
Input : Graph G
Output : 각 node의 parent

idea
- 시작점을 1로 시작하여 Graph를 BFS 방식으로 탐색한다.
- 탐색하면서 각 node의 parent를 저장한다.
- 중복 탐색을 막기 위해 방문 여부를 체크하면서 탐색한다.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int NodeCount;                    // 전체 node의 개수
bool visited[100001];             // 각 node의 방문 여부
vector<int> Graph[100001];        // Graph G
int ParentNode[100001];           // 각 node들의 parent

void BFS()
{
    queue<int> next;               // 다음에 탐색할 node들
    int CurrentNode;               // 현재 탐색하고 있는 node

    // 시작 node(1)를 queue에 넣고 방문했다고 체크
    next.push(1);
    visited[1] = true;

    while (!next.empty())
    {
        // queue에서 하나를 꺼낸다.
        CurrentNode = next.front();
        next.pop();

        // 현재 node와 연결된 node 중 방문하지 않는 node를 탐색한다.
        for (int i = 0; i < Graph[CurrentNode].size(); i++)
        {
            if (!visited[Graph[CurrentNode][i]])
            {
                // 방문 여부 표시, parent를 현재 node로 저장
                visited[Graph[CurrentNode][i]] = true;
                ParentNode[Graph[CurrentNode][i]] = CurrentNode;

                // queue에 다음에 탐색할 node를 push
                next.push(Graph[CurrentNode][i]);
            }
        }
    }
}

int main()
{
    int tmp1, tmp2;

    // 전체 node의 개수와 Graph를 입력
    cin >> NodeCount;
    for (int i = 0; i < NodeCount - 1; i++)
    {
        cin >> tmp1 >> tmp2;

        Graph[tmp1].push_back(tmp2);
        Graph[tmp2].push_back(tmp1);
    }

    // 시작점 1부터 BFS 방식으로 탐색해 각 node의 parent를 찾기
    BFS();

    // 2번 node부터 시작하여, 각 node들의 parent를 출력
    for (int i = 2; i <= NodeCount; i++)
        cout << ParentNode[i] << '\n';

    return 0;
}