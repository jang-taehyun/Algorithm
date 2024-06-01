#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct _node
{
    int y;
    int x;
} Node;

int board[300][300];
bool visited[300][300];
bool exist[300][300];
int column, row;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
queue<Node> ice;

void BFS(int cx, int cy)
{
    queue<Node> search;
    Node cur, next;

    visited[cy][cx] = true;
    search.push({ cy, cx });

    while (!search.empty())
    {
        cur.x = search.front().x;
        cur.y = search.front().y;
        search.pop();

        for (int i = 0; i < 4; i++)
        {
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];

            if (next.x < 0 || next.x >= row || next.y < 0 || next.y >= column)
                continue;
            if (visited[next.y][next.x])
                continue;
            if (!exist[next.y][next.x])
                continue;

            search.push(next);
            visited[next.y][next.x] = true;
        }
    }
}

int main()
{
    bool flag = false;
    int size;
    Node cur, next;
    int res = 0, iceCount = 0;

    cin >> column >> row;
    for (int i = 0; i < column; i++)
        for (int j = 0; j < row; j++)
        {
            cin >> board[i][j];
            if (board[i][j])
            {
                ice.push({ i, j });
                exist[i][j] = true;
                iceCount++;
            }
        }

    while (iceCount)
    {
        memset(visited, false, sizeof(visited));
        flag = false;
        res++;

        size = ice.size();
        for (int j = 0; j < size; j++)
        {
            cur.x = ice.front().x;
            cur.y = ice.front().y;
            ice.pop();
            ice.push(cur);

            for (int k = 0; k < 4; k++)
            {
                next.x = cur.x + dx[k];
                next.y = cur.y + dy[k];

                if (next.x < 0 || next.x >= row || next.y < 0 || next.y >= column)
                    continue;
                if (exist[next.y][next.x])
                    continue;

                board[cur.y][cur.x]--;
                if (!board[cur.y][cur.x])
                    break;
            }
        }

        for (int j = 0; j < size; j++)
        {
            cur.x = ice.front().x;
            cur.y = ice.front().y;
            ice.pop();

            if (!board[cur.y][cur.x])
            {
                iceCount--;
                exist[cur.y][cur.x] = false;
            }
            else
                ice.push(cur);
        }

        if (!iceCount)
            break;

        size = ice.size();
        for (int j = 0; j < size; j++)
        {
            cur.x = ice.front().x;
            cur.y = ice.front().y;
            ice.pop();
            ice.push(cur);

            if (!visited[cur.y][cur.x])
            {
                if (flag)
                {
                    cout << res;
                    return 0;
                }

                flag = true;
                BFS(cur.x, cur.y);
            }
        }
    }

    cout << 0;

    return 0;
}