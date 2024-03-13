/*
problem : n*m board에 빨간 구슬과 파란 구슬의 위치가 주어졌을 때, 빨간 구슬만 구멍에 넣을 수 있도록 기울이는 횟수의 최소값을 구해라.
input : n*m board, 빨간 구슬의 위치, 파란 구슬의 위치
output : board에서 빨간 구슬을 구멍에 넣을 때 기울이는 횟수의 최소값

idea
- 상하좌우 중 기울일 방향을 지정하고 구슬이 벽을 만나거나 구멍을 만날때까지 이동한다.
- 구슬이 이동할 때마다 구슬의 위치를 update한다.
- 파란 구슬이 들어가면 무효 처리를 한다.
- 두 개의 구슬이 모두 구멍에 들어가지 않으면 다음에 기을일 방향을 정하고 이전 과정을 반복한다.
- 이 과정을 BFS 탐색을 이용해 탐색한다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

char Board[10][10];                    // m*n board의 정보
int Column, Row;                       // board의 column, row 길이
int MinimumTiltCount;                  // 기울이는 최소값
int dx[4] = { 0, 0, 1, -1 };           // board를 기울이는 방향
int dy[4] = { -1, 1, 0, 0 };
bool visited[10][10][10][10];          // 해당 좌표를 방문했는지 여부

typedef struct _p
{
    int rx;
    int ry;
    int bx;
    int by;
    int cnt;
} BallPoints;

int MoveBall(int* x, int* y, int dir)
{
    int MoveCount = 0;

    // 벽이나 구멍을 만날때까지 계속 이동
    while (Board[*x + dx[dir]][*y + dy[dir]] != '#' &&
        Board[*x][*y] != 'O')
    {
        *x += dx[dir];
        *y += dy[dir];
        MoveCount++;
    }

    // 공이 이동한 횟수를 return
    return MoveCount;
}

int BFS(int rx, int ry, int bx, int by)
{
    int crx, cry, cbx, cby;                    // 빨간공과 파란공의 현재 위치
    int nrx, nry, nbx, nby;                    // 빨간공과 파란공의 다음 위치
    int cnt = 0;                                 // 기울인 횟수
    queue<BallPoints> Search;                  // 다음에 탐색할 공들의 위치
    int RedBallMoveCount, BlueBallMoveCount;   // 빨간공과 파란공이 움직인 칸의 개수

    // 처음 위치를 queue에 넣고, 방문 처리
    Search.push({ rx, ry, bx, by, cnt });
    visited[rx][ry][bx][by] = true;

    while (!Search.empty())
    {
        // 탐색할 공들의 위치를 꺼낸다.
        crx = Search.front().rx;
        cry = Search.front().ry;
        cbx = Search.front().bx;
        cby = Search.front().by;
        cnt = Search.front().cnt;
        Search.pop();

        // 만약 10회 초과로 기울인다면 loop를 종료
        if (cnt >= 10)
            break;

        // 4방향을 모두 탐색해 공들의 다음 위치를 구한다.
        for (int i = 0; i < 4; i++)
        {
            nrx = crx;
            nry = cry;
            nbx = cbx;
            nby = cby;

            RedBallMoveCount = MoveBall(&nrx, &nry, i);
            BlueBallMoveCount = MoveBall(&nbx, &nby, i);

            // 이미 방문한 좌표들이라면 다음 위치들을 파악한다.
            if (visited[nrx][nry][nbx][nby])
                continue;

            // 만약 파란공이 구멍에 들어가면 다른 위치 탐색
            if (Board[nbx][nby] == 'O')
                continue;

            // 만약 빨간공이 구멍에 들어가면 기울인 횟수를 return
            if (Board[nrx][nry] == 'O')
                return cnt + 1;

            // 만약 두 공의 위치가 같다면, 더 많이 움직인 공을 한 칸 뒤로 이동
            if (nrx == nbx && nry == nby)
            {
                if (RedBallMoveCount > BlueBallMoveCount)
                {
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else
                {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            // 공들의 위치를 queue에 push
            Search.push({ nrx, nry, nbx, nby, cnt + 1 });
            visited[nrx][nry][nbx][nby] = true;
        }
    }

    return -1;
}

int main()
{
    string input;
    int rx, ry, bx, by;

    // m*n board의 정보 입력
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;

        for (int j = 0; j < Row; j++)
        {
            Board[i][j] = input[j];

            // 만약 구슬을 만난다면 구슬의 위치를 기억하고 통로로 변경
            if (Board[i][j] == 'R')
            {
                rx = i;
                ry = j;
                Board[i][j] = '.';
            }
            if (Board[i][j] == 'B')
            {
                bx = i;
                by = j;
                Board[i][j] = '.';
            }
        }
    }

    // 4가지 방향 중 하나를 선택해 board를 기울이고 구슬을 이동
    // 그 후 결과값을 출력
    cout << BFS(rx, ry, bx, by);

    return 0;
}