/*
problem : n*m board 안에서 (1, 1)부터 시작해 최대 k개의 벽을 부수고 (n, m)에 도달하는 최단 거리를 구해라.
input : n*m board, 부술 수 있는 벽의 개수 k
output : (1, 1)부터 시작해 최대 k개의 벽을 부수고 (n, m)에 도달하는 최단 거리

idea
- root를 (1, 1), level이 이동한 칸의 개수, node가 상하좌우로 움직인 후의 좌표와 벽을 몇 개 부섰는지 나타내는 숫자로 구성해 tree를 만든다.
- tree를 BFS 방식으로 탐색한다.
- 상하좌우로 움직이고 부순 벽의 개수가 같은 node는 더 이상 탐색하지 않는다.
*/
#include <iostream>
#include <queue>
#include <string>
#define BOUND 1000
#define BREAK_WALL_MAX_COUNT 10
using namespace std;

// node
typedef struct _node
{
    int x;
    int y;
    int BreakWall;
} Node;

int Column, Row;                                        // board의 column, row
int BreakWallCount;                                     // 부술 수 있는 벽의 개수
int Board[BOUND][BOUND];                                // n*m board
bool Search[BOUND][BOUND][BREAK_WALL_MAX_COUNT];        // node의 탐색 여부
int dx[4] = { 0, 0, 1, -1 };                              // 이동 경로
int dy[4] = { -1, 1, 0, 0 };

// 범위, 탐색 여부 검사(promising 검사)
bool IsPromising(int x, int y, int BreaWallCount);

// node 탐색
int BFS();

int main()
{
    string input;

    // n*m board의 정보 입력
    cin >> Column >> Row >> BreakWallCount;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;
        for (int j = 0; j < Row; j++)
            Board[i][j] = input[j] - '0';
    }

    // tree를 BFS 방식으로 탐색해 최단 거리를 구한다.
    cout << BFS();

    return 0;
}

bool IsPromising(Node& ref)
{
    // 범위 검사
    if (ref.x < 0 || ref.x >= Column || ref.y < 0 || ref.y >= Row)
        return false;

    // 탐색 여부 검사
    if (Search[ref.x][ref.y][ref.BreakWall])
        return false;

    return true;
}

int BFS()
{
    queue<Node> next;                // 다음에 탐색할 node
    int MoveCount = 1;                 // 칸을 이동한 횟수(level)
    int QueueSize = 0;                 // queue의 크기
    Node CurrentNode, NextNode;      // 현재 node, 다음 node

    // 시작점을 queue에 넣고 탐색 설정
    Search[0][0][0] = true;
    next.push({ 0, 0, 0 });

    // 탐색
    while (!next.empty())
    {
        // 한 level의 탐색을 queue의 크기만큼 반복
        QueueSize = next.size();
        while (QueueSize--)
        {
            CurrentNode.x = next.front().x;
            CurrentNode.y = next.front().y;
            CurrentNode.BreakWall = next.front().BreakWall;
            next.pop();

            // 도착점에 도착했다면 level을 return
            if (CurrentNode.x == Column - 1 && CurrentNode.y == Row - 1)
                return MoveCount;

            // 4가지 이동 방향 탐색
            for (int i = 0; i < 4; i++)
            {
                NextNode.x = CurrentNode.x + dx[i];
                NextNode.y = CurrentNode.y + dy[i];
                NextNode.BreakWall = CurrentNode.BreakWall;

                // 범위, 탐색 여부 검사(promising 검사)
                if (!IsPromising(NextNode))
                    continue;

                // 빈 공간인 경우
                if (!Board[NextNode.x][NextNode.y])
                {
                    Search[NextNode.x][NextNode.y][NextNode.BreakWall] = true;
                    next.push(NextNode);
                }
                // 벽이면서 벽을 부술 수 있는 횟수가 남은 경우
                if (Board[NextNode.x][NextNode.y] && NextNode.BreakWall < BreakWallCount)
                {
                    Search[NextNode.x][NextNode.y][NextNode.BreakWall] = true;
                    NextNode.BreakWall++;
                    Search[NextNode.x][NextNode.y][NextNode.BreakWall] = true;
                    next.push(NextNode);
                }
            }
        }

        // 칸을 이동한 횟수(level) 증가
        MoveCount++;
    }

    // 방법을 찾지 못했으므로 -1을 return
    return -1;
}