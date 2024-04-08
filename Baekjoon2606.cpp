/*
problem : graph 상에서 1번 node에서부터 갈 수 있는 node들의 개수를 구해라.
input : graph
output : 1번 node에서부터 갈 수 있는 node들의 개수

idea
- 1번 node부터 시작해 BFS 방식으로 탐색한다.
- node를 방문할 때마다 결과값을 1씩 증가한다.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];            // graph
int NodeCount;                     // 전체 node의 개수
bool IsSearch[101];                  // 각 node의 탐색 여부
int res = 0;                         // 결과값

void BFS()
{
    queue<int> search;            // 다음에 탐색할 node들
    int cur, next;                // 현재 node, 다음 node

    // 시작점(1)을 queue에 넣고 방문 처리
    search.push(1);
    IsSearch[1] = true;

    while (!search.empty())
    {
        cur = search.front();
        search.pop();

        // 연결되어 있는 node들 중 아직 방문하지 않는 node를 queue에 넣는다.
        for (int i = 0; i < graph[cur].size(); i++)
        {
            next = graph[cur][i];

            if (IsSearch[next])
                continue;

            search.push(next);
            IsSearch[next] = true;
            res++;
        }
    }
}

int main()
{
    int n1, n2, EdgeCount;

    // graph 입력
    cin >> NodeCount;
    cin >> EdgeCount;
    for (int i = 0; i < EdgeCount; i++)
    {
        cin >> n1 >> n2;

        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    // BFS 탐색
    BFS();

    // 결과값 출력
    cout << res;

    return 0;
}