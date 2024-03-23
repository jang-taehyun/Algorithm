/*
problem : n*m board에서 빈 칸(0인 칸)과 벽(1인 칸)이 있다. (1, 1)부터 시작하여 (n, m)까지 가는 최단 거리를 구하는데,
          한 번 이동할 때마다 낮과 밤이 바뀐다. 가만히 있는 경우에도 낮과 밤이 바뀌고, 이런 경우에는 방문한 칸의 개수가 하나 늘어나는 것으로 생각한다.
          벽은 낮에만 부술 수 있고, 최대 k까지만 부술 수 있다.
          이러한 조건을 고려해 (1, 1)부터 시작하여 (n, m)까지 가는 최단 거리를 구해라.
input : n*m board, 부술 수 있는 벽의 개수 k
output : 조건을 고려해 (1, 1)부터 시작하여 (n, m)까지 가는 최단 거리

idea
- root가 (1, 1), level이 이동한 칸의 개수, node가 이동한 후의 위치와 밤낮의 상태, 부순 벽의 개수를 나타내는 tree를 만든다.
- tree를 BFS 방식으로 탐색한다.
- 이미 탐색한 node는 다시 탐색하지 않는다.
- promising 조건 : 범위를 넘어가지 않을 때, 아직 탐색하지 않은 node일 때
*/
#include <iostream>
#include <queue>
#include <string>
#define BOUND 1000
#define BREAK_WALL_MAX_COUNT 11
#define STATE 2
using namespace std;

typedef struct _node
{
    int x;            // 좌표
    int y;
    int BreakWall;    // 부순 벽의 개수
    int State;        // 0 : 낮, 1 : 밤
} Node;

int Column, Row;                                        // board의 column, row
int Board[BOUND][BOUND];                                // board의 상태
bool Search[BOUND][BOUND][BREAK_WALL_MAX_COUNT][STATE]; // node의 탐색 여부
                                                        // 0 : 낮, 1 : 밤
int BreakWallCount;                                     // 부술 수 있는 벽의 개수
int dx[4] = { 0, 0, 1, -1 };                              // 이동 방향
int dy[4] = { -1, 1, 0, 0 };

// promising 검사
bool Promising(const Node& Check);

// node 탐색
int BFS();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;

    // n*m board의 정보와 부술 수 있는 벽의 개수 입력
    cin >> Column >> Row >> BreakWallCount;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;
        for (int j = 0; j < Row; j++)
            Board[i][j] = input[j] - '0';
    }

    // BFS 방식으로 tree를 탐색하고 결과값을 출력
    cout << BFS();

    return 0;
}

bool Promising(const Node& Check)
{
    if (Check.x < 0 || Check.x >= Column || Check.y < 0 || Check.y >= Row)
        return false;
    if (Search[Check.x][Check.y][Check.BreakWall][Check.State])
        return false;
    return true;
}

int BFS()
{
    queue<Node> next;            // 다음에 탐색할 node들의 집합
    Node CurrentNode, NextNode;  // 현재 node, 다음 node
    int MoveCount = 1;             // 이동한 칸의 개수(level)
    int QueueSize;               // queue의 크기(한 level의 node 개수)

    // 시작점(1, 1)을 queue에 넣고 탐색 설정
    Search[0][0][0][0] = true;
    next.push({ 0, 0, 0, 0 });

    // 탐색
    while (!next.empty())
    {
        // queue의 크기만큼 반복
        QueueSize = next.size();
        while (QueueSize--)
        {
            CurrentNode.x = next.front().x;
            CurrentNode.y = next.front().y;
            CurrentNode.BreakWall = next.front().BreakWall;
            CurrentNode.State = next.front().State;
            next.pop();

            // 도착점에 도착했다면 level을 return
            if (CurrentNode.x == Column - 1 && CurrentNode.y == Row - 1)
                return MoveCount;

            // 다음에 탐색할 칸들을 queue에 넣는다.
            for (int i = 0; i < 4; i++)
            {
                NextNode.x = CurrentNode.x + dx[i];
                NextNode.y = CurrentNode.y + dy[i];
                NextNode.BreakWall = CurrentNode.BreakWall;
                NextNode.State = !(CurrentNode.State);

                // promising 검사
                if (!Promising(NextNode))
                    continue;

                // 빈 칸인 경우
                if (!Board[NextNode.x][NextNode.y])
                {
                    Search[NextNode.x][NextNode.y][NextNode.BreakWall][NextNode.State] = true;
                    next.push(NextNode);
                }

                // 벽이면서 부술 수 있는 벽의 개수가 남아있는 경우
                if (Board[NextNode.x][NextNode.y] && NextNode.BreakWall < BreakWallCount)
                {
                    // 현재 낮인 상태
                    if (!CurrentNode.State && !Search[NextNode.x][NextNode.y][NextNode.BreakWall + 1][NextNode.State])
                    {
                        NextNode.BreakWall++;
                        Search[NextNode.x][NextNode.y][NextNode.BreakWall][NextNode.State] = true;
                        next.push(NextNode);
                    }
                    // 현재 밤인 상태
                    else if (CurrentNode.State && !Search[CurrentNode.x][CurrentNode.y][CurrentNode.BreakWall][!CurrentNode.State])
                    {
                        Search[CurrentNode.x][CurrentNode.y][CurrentNode.BreakWall][!CurrentNode.State] = true;
                        next.push({ CurrentNode.x, CurrentNode.y, CurrentNode.BreakWall, !CurrentNode.State });
                    }
                }
            }
        }

        // level 증가
        MoveCount++;
    }

    // 도착점에 도착하는 것이 불가능하므로 -1을 return
    return -1;
}