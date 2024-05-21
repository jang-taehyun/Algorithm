#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

typedef struct _node
{
    int z;
    int y;
    int x;
} Node;

char board[30][30][30];
bool visited[30][30][30];
int level, row, column;
int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dy[6] = { -1, 1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };
Node start;

bool IsRange(Node& ref)
{
    if (ref.z < 0 || ref.z >= level || ref.y < 0 || ref.y >= column || ref.x < 0 || ref.x >= row)
        return false;
    return true;
}

int BFS()
{
    queue<Node> search;
    Node cur, next;
    int time = 0;
    int size;

    search.push(start);
    visited[start.z][start.y][start.x] = true;

    while (!search.empty())
    {
        size = search.size();
        while (size--)
        {
            cur.x = search.front().x;
            cur.y = search.front().y;
            cur.z = search.front().z;
            search.pop();

            if ('E' == board[cur.z][cur.y][cur.x])
                return time;

            for (int i = 0; i < 6; i++)
            {
                next.x = cur.x + dx[i];
                next.y = cur.y + dy[i];
                next.z = cur.z + dz[i];

                if (!IsRange(next))
                    continue;
                if (visited[next.z][next.y][next.x])
                    continue;
                if ('#' == board[next.z][next.y][next.x])
                    continue;

                search.push(next);
                visited[next.z][next.y][next.x] = true;
            }
        }

        time++;
    }

    return -1;
}

int main()
{
    string input;
    int res;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        cin >> level >> column >> row;
        if (!level && !column && !row)
            break;

        for (int i = 0; i < level; i++)
            for (int j = 0; j < column; j++)
            {
                cin >> input;

                for (int k = 0; k < row; k++)
                {
                    board[i][j][k] = input[k];

                    if ('S' == board[i][j][k])
                    {
                        start.z = i;
                        start.y = j;
                        start.x = k;

                        board[i][j][k] = '.';
                    }
                }
            }

        res = BFS();
        if (-1 == res)
            cout << "Trapped!" << '\n';
        else
            cout << "Escaped in " << res << " minute(s)." << '\n';

        memset(board, 0, sizeof(board));
        memset(visited, false, sizeof(visited));
        start.z = 0;
        start.y = 0;
        start.x = 0;
    }

    return 0;
}