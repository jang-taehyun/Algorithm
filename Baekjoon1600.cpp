#include <iostream>
#include <queue>
using namespace std;

typedef struct _node
{
    int y;
    int x;
    int remain;
} Node;

int UseCount;
int row, column;
bool board[200][200];
bool visited[200][200][31];
int dy1[4] = { -1, 1, 0, 0 };
int dx1[4] = { 0, 0, -1, 1 };
int dy2[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dx2[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int BFS()
{
    queue<Node> search;
    Node cur, next;
    int level = 0;
    int size;

    visited[0][0][UseCount] = true;
    search.push({ 0, 0, UseCount });

    while (!search.empty())
    {
        size = search.size();
        while (size--)
        {
            cur.x = search.front().x;
            cur.y = search.front().y;
            cur.remain = search.front().remain;
            search.pop();

            if (cur.y == column - 1 && cur.x == row - 1)
                return level;

            for (int i = 0; i < 4; i++)
            {
                next.x = cur.x + dx1[i];
                next.y = cur.y + dy1[i];
                next.remain = cur.remain;

                if (next.x < 0 || next.x >= row || next.y < 0 || next.y >= column)
                    continue;
                if (visited[next.y][next.x][next.remain])
                    continue;
                if (board[next.y][next.x])
                    continue;

                search.push(next);
                visited[next.y][next.x][next.remain] = true;
            }

            if (cur.remain)
            {
                for (int i = 0; i < 8; i++)
                {
                    next.x = cur.x + dx2[i];
                    next.y = cur.y + dy2[i];
                    next.remain = cur.remain - 1;

                    if (next.x < 0 || next.x >= row || next.y < 0 || next.y >= column)
                        continue;
                    if (visited[next.y][next.x][next.remain])
                        continue;
                    if (board[next.y][next.x])
                        continue;

                    search.push(next);
                    visited[next.y][next.x][next.remain] = true;
                }
            }
        }

        level++;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> UseCount;
    cin >> row >> column;
    for (int i = 0; i < column; i++)
        for (int j = 0; j < row; j++)
            cin >> board[i][j];

    cout << BFS();

    return 0;
}