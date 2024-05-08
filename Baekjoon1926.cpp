#include <iostream>
#include <queue>
#define MAX(x, y) (x) > (y) ? (x) : (y)
using namespace std;

typedef struct _node
{
    int x;
    int y;
} Node;

int board[500][500];
int column, row;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int mark = 1;
int MaxSize = 0;

int BFS(int cx, int cy)
{
    queue<Node> SearchNodes;
    Node cur, next;
    int size = 1;

    mark++;
    board[cx][cy] = mark;
    SearchNodes.push({ cx, cy });

    while (!SearchNodes.empty())
    {
        cur.x = SearchNodes.front().x;
        cur.y = SearchNodes.front().y;
        SearchNodes.pop();

        for (int i = 0; i < 4; i++)
        {
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];

            if (next.x < 0 || next.x >= column || next.y < 0 || next.y >= row)
                continue;
            if (1 != board[next.x][next.y])
                continue;

            board[next.x][next.y] = mark;
            size++;
            SearchNodes.push(next);
        }
    }

    return size;
}

int main()
{
    int tmp;

    cin >> column >> row;
    for (int i = 0; i < column; i++)
        for (int j = 0; j < row; j++)
            cin >> board[i][j];

    for (int i = 0; i < column; i++)
        for (int j = 0; j < row; j++)
        {
            if (1 == board[i][j])
            {
                tmp = BFS(i, j);
                MaxSize = MAX(tmp, MaxSize);
            }
        }

    printf("%d\n%d\n", mark - 1, MaxSize);

    return 0;
}