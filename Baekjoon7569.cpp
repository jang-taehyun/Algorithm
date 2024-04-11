/*
problem : n*m*h 크기를 가지는 3차원 배열 S 안에 0인 칸들이 모두 1이 될 때까지 걸리는 시간을 구해라.
input : n*m*h 크기를 가지는 3차원 배열 S
output : 배열 S 안에 0인 칸들이 모두 1이 될 때까지 걸리는 시간

idea
- root가 배열 S 안에서 1인 칸들, level이 지나간 시간, node가 다음으로 탐색할 칸들을 나타내는 tree를 만든다.
- tree를 BFS 방식으로 탐색한다.
- non-promising 조건
  1) 이미 방문한 칸인 경우
  2) 배열 S의 범위를 넘어간 경우
  3) 0이 아닌 칸을 만난 경우
- 모든 탐색이 끝난 후, 배열 S를 검사해 아직 0인 칸이 있는지 확인한다.
  - 만약 0인 칸이 있다면 -1을 출력
- 알고리즘 시간 : 100*100*100*6 + 100*100*100 = 7*10^6
  메모리 : 100*100*100*2*5 = 10^7byte -> 10^4 kb -> 10 mb
*/
#include <iostream>
#include <queue>
using namespace std;

// node
typedef struct _node
{
    int c;
    int r;
    int h;

    void operator=(struct _node& ref)
    {
        c = ref.c;
        r = ref.r;
        h = ref.h;
    }
} Node;

int Column, Row, Height;            // 3차원 배열 S의 가로, 세로, 높이
int S[100][100][100];               // 3차원 배열 S
bool IsVisited[100][100][100];      // 각 칸의 방문 여부
queue<Node> Search;                 // 다음에 탐색할 노드들
int Time = -1;                      // 지난 시간들

int dx[6] = { -1, 0, 1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

bool Promising(Node& check)
{
    if (check.c < 0 || check.c >= Column ||
        check.r < 0 || check.r >= Row ||
        check.h < 0 || check.h >= Height)
        return false;

    if (IsVisited[check.c][check.r][check.h])
        return false;

    if (S[check.c][check.r][check.h] == 1 || S[check.c][check.r][check.h] == -1)
        return false;

    return true;
}

void BFS()
{
    int NodeCount;                   // 한 level에 있는 node의 개수
    Node cur, next;                  // 현재 node, 다음 node

    while (!Search.empty())
    {
        // level 증가
        Time++;

        // 한 level에 있는 node의 개수만큼 반복
        NodeCount = Search.size();
        while (NodeCount--)
        {
            cur = Search.front();
            Search.pop();

            for (int i = 0; i < 6; i++)
            {
                next.c = cur.c + dx[i];
                next.r = cur.r + dy[i];
                next.h = cur.h + dz[i];

                if (!Promising(next))
                    continue;

                IsVisited[next.c][next.r][next.h] = true;
                S[next.c][next.r][next.h] = 1;
                Search.push(next);
            }
        }
    }
}

int main()
{
    // 3차원 배열 S 입력
    cin >> Row >> Column >> Height;
    for (int i = 0; i < Height; i++)
        for (int j = 0; j < Column; j++)
            for (int k = 0; k < Row; k++)
            {
                cin >> S[j][k][i];

                if (S[j][k][i] == 1)
                {
                    IsVisited[j][k][i] = true;
                    Search.push({ j, k, i });
                }
            }

    // tree를 BFS 방식으로 탐색
    BFS();

    // 3차원 배열 S를 탐색해 0인 칸이 존재하는지 확인하고,
    // 만약 0인 칸이 존재한다면 -1을 출력
    for (int i = 0; i < Height; i++)
        for (int j = 0; j < Column; j++)
            for (int k = 0; k < Row; k++)
            {
                if (!S[j][k][i])
                {
                    cout << -1;
                    return 0;
                }
            }
    cout << Time;

    return 0;
}