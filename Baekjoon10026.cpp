#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

char board[100][100];
int len;
bool visited[100][100];
int mark = 0;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS(int x, int y, char color, bool anomoly)
{
    queue<pair<int, int>> search;
    int cx, cy, nx, ny;

    mark++;
    visited[x][y] = true;
    search.push(make_pair(x, y));

    while (!search.empty())
    {
        cx = search.front().first;
        cy = search.front().second;
        search.pop();

        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (nx < 0 || nx >= len || ny < 0 || ny >= len)
                continue;
            if (visited[nx][ny])
                continue;
            if (anomoly && color != board[nx][ny] && (color == 'B' || board[nx][ny] == 'B'))
                continue;
            else if (!anomoly && color != board[nx][ny])
                continue;

            visited[nx][ny] = true;
            search.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;

    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> input;
        for (int j = 0; j < len; j++)
            board[i][j] = input[j];
    }

    for (int loop = 0; loop < 2; loop++)
    {
        mark = 0;
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                if (!visited[i][j])
                    BFS(i, j, board[i][j], loop);

        cout << mark << ' ';
    }

    return 0;
}