#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct _p
{
    int x;
    int y;
} Pos;

int board[50][50];
int column, row;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int mark = 1;

void BFS(int cx, int cy)
{
    queue<Pos> search;
    Pos cur, next;

    mark++;
    board[cy][cx] = mark;
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

            if (next.x < 0 || next.x >= row || next.y < 0 || next.y >= column)
                continue;
            if (1 != board[next.y][next.x])
                continue;

            board[next.y][next.x] = mark;
            search.push(next);
        }
    }
}

int main()
{
    int test, x, y, cnt;
    scanf("%d", &test);

    while (test--)
    {
        scanf("%d %d %d", &row, &column, &cnt);
        while (cnt--)
        {
            scanf("%d %d", &x, &y);
            board[y][x] = 1;
        }

        for (int i = 0; i < column; i++)
            for (int j = 0; j < row; j++)
                if (1 == board[i][j])
                    BFS(j, i);

        printf("%d\n", mark - 1);

        mark = 1;
        memset(board, 0, sizeof(board));
    }

    return 0;
}