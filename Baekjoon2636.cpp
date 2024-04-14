/*
problem : n*m board에서 1인 칸이 모두 0으로 바뀌는데 걸리는 시간과 모두 0으로 바뀌기 직전 시간에 남아있는 1인 칸의 개수를 구해라.
input : n*m board
output : board에서 1인 칸이 모두 0으로 바뀌는데 걸리는 시간, 모두 0으로 바뀌기 직전 시간에 남아있는 1인 칸의 개수

idea
- board를 root가 (0, 0), node가 이동 후의 칸의 위치와 칸의 상태(0 또는 1)인 tree로 만든다.
- tree를 BFS 방식으로 탐색한다.
- non-promising 조건
  1) 이미 방문했던 칸을 다시 방문하는 경우, board의 범위를 벗어나는 경우
  2) 방문한 칸의 상태가 1인 경우 -> 방문한 칸의 상태를 0으로 만들고 count를 센다.
      -> 여기서 센 count는 탐색이 모두 끝나면 두 번째 output으로 출력한다.
- tree를 모두 탐색할 때까지 탐색을 반복하고, (반복한 횟수-1)를 첫 output으로 출력한다.

https://ongveloper.tistory.com/159
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool Tree[100][100];            // Tree
int Column, Row;                // board의 column, row
bool visited[100][100];         // 현재 칸의 방문 여부
int RemoveCount;                // 탐색할 때 0으로 바꾼 칸의 개수
int dx[4] = { 0, 0, 1, -1 };      // 탐색 방향
int dy[4] = { 1, -1, 0, 0 };

bool IsAbleSearch(int x, int y)
{
    if (x < 0 || x >= Column || y < 0 || y >= Row)
        return false;
    if (visited[x][y])
        return false;
    return true;
}

bool BFS()
{
    queue<pair<int, int>> next;        // 다음에 탐색할 칸들
    int cx, cy, nx, ny;                // 현재 위치, 다음 위치
    int cnt = 0;

    next.push(make_pair(0, 0));
    visited[0][0] = true;

    // 탐색
    while (!next.empty())
    {
        cx = next.front().first;
        cy = next.front().second;
        next.pop();

        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (IsAbleSearch(nx, ny))
            {
                visited[nx][ny] = true;

                // 다음 칸이 1인 경우
                if (Tree[nx][ny])
                {
                    Tree[nx][ny] = false;
                    cnt++;
                }
                // 다음 칸이 0인 경우
                else
                {
                    next.push(make_pair(nx, ny));
                }
            }
        }
    }

    // 1로 바뀐 칸이 없는 경우, false 반환
    if (!cnt)
        return false;

    // 1로 바뀐 칸이 하나라도 있으면,
    // 2번째 output을 update후 true 반환
    RemoveCount = cnt;
    return true;
}

int main()
{
    int loopCount = 0;                // BFS 탐색을 시도한 횟수

    // n*m board 입력
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
        for (int j = 0; j < Row; j++)
            cin >> Tree[i][j];

    // BFS 탐색
    while (BFS())
    {
        loopCount++;
        memset(visited, false, sizeof(visited));
    }

    // 결과값 출력
    cout << loopCount << ' ' << RemoveCount;

    return 0;
}