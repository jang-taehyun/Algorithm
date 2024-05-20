#include <iostream>
#include <queue>
#include <cstring>
#define MAX(x, y) (x) > (y) ? (x) : (y)
using namespace std;

typedef struct _node
{
    int x;
    int y;
} Node;

int board[100][100];
int len;
bool visited[100][100];
bool IsExist[101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void BFS(int cx, int cy, int num)
{
    queue<Node> search;
    Node cur, next;

    visited[cx][cy] = true;
    search.push({ cx, cy });

    while (!search.empty())
    {
        cur.x = search.front().x;
        cur.y = search.front().y;
        search.pop();

        for (int i = 0; i < 4; i++)
        {
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];

            if (next.x < 0 || next.x >= len || next.y < 0 || next.y >= len)
                continue;
            if (visited[next.x][next.y])
                continue;
            if (board[next.x][next.y] <= num)
                continue;

            search.push(next);
            visited[next.x][next.y] = true;
        }
    }
}

int main()
{
    int tmp;
    int res = 1;
    int Maximum = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> len;
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
        {
            cin >> board[i][j];
            IsExist[board[i][j]] = true;
            Maximum = MAX(Maximum, board[i][j]);
        }

    for (int num = 1; num <= 100; num++)
    {
        if (num > Maximum)
            break;

        if (!IsExist[num])
            continue;

        memset(visited, false, sizeof(visited));
        tmp = 0;

        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                if (!visited[i][j] && board[i][j] > num)
                {
                    tmp++;
                    BFS(i, j, num);
                }

        res = MAX(res, tmp);
    }

    cout << res;


    return 0;
}