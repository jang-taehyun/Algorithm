/*
problem : n*m board을 서로 다른 크기를 가진 직사각형으로 덮을때 덮여지지 않는 면적의 개수와 크기를 구해라.
input : n*m board의 크기, 서로 다른 크기를 가진 직사각형을 정의하는 2개의 정점들
output : n*m board을 서로 다른 크기를 가진 직사각형으로 덮을때 덮여지지 않는 면적의 개수와 크기

idea
- 서로 다른 크기를 가진 직사각형의 시작점과 끝점을 입력받을 때,
  끝점은 x, y 좌표에 -1을 하고 범위에 속한 칸들은 모두 제외한다.
- n*m board를 BFS로 탐색해 분리된 영역의 개수와 크기를 구한다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int Column, Row;                    // board의 column, row의 길이
bool Board[101][101];               // n*m board
                                    // 0 : 방문하지 않음, 1 : 덮여진 칸 또는 이미 count한 칸
int dx[4] = { 0, 0, -1, 1 };          // 이동 방향
int dy[4] = { -1, 1, 0, 0 };

bool Promising(int x, int y)
{
    if (x < 0 || x >= Column || y < 0 || y >= Row)
        return false;
    if (Board[x][y])
        return false;
    return true;
}

int BFS(int sx, int sy)
{
    queue<pair<int, int>> next;        // 다음에 탐색할 칸들
    int cx, cy, nx, ny;                // 현재 위치, 다음 위치
    int cnt = 1;

    next.push(make_pair(sx, sy));
    Board[sx][sy] = true;

    while (!next.empty())
    {
        cx = next.front().first;
        cy = next.front().second;
        next.pop();

        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (!Promising(nx, ny))
                continue;

            cnt++;
            Board[nx][ny] = true;
            next.push(make_pair(nx, ny));
        }
    }

    return cnt;
}

int main()
{
    vector<int> Size;                // 덮여지지 않는 면적의 크기들
    int sx, sy, lx, ly;              // 시작점, 끝점
    int cnt;                         // 덮여질 사각형의 개수

    // n*m board 정보 및 덮여질 사각형들의 정보 입력
    cin >> Column >> Row >> cnt;
    while (cnt--)
    {
        cin >> sy >> sx >> ly >> lx;
        lx -= 1;
        ly -= 1;

        for (int i = sx; i <= lx; i++)
            for (int j = sy; j <= ly; j++)
                Board[i][j] = true;
    }

    // board를 BFS 탐색
    for (int i = 0; i < Column; i++)
        for (int j = 0; j < Row; j++)
            if (!Board[i][j])
                Size.push_back(BFS(i, j));

    // 오름차순으로 sort
    sort(Size.begin(), Size.end());

    // 결과값 출력
    cout << Size.size() << ' ';
    for (int i = 0; i < Size.size(); i++)
        cout << Size[i] << ' ';

    return 0;
}