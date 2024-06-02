#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef unsigned int UINT;
typedef struct _node
{
    int y;
    int x;
} Node;

char board[1000][1000];
int column, row;
int player = 0;
UINT MoveCount[10];
UINT result[10];
queue<Node> search[10];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS(int _playerNumber)
{
    Node cur, next;
    int size;

    for (UINT i = 0; i < MoveCount[_playerNumber]; i++)
    {
        if (search[_playerNumber].empty())
            break;

        size = search[_playerNumber].size();
        while (size--)
        {
            cur.y = search[_playerNumber].front().y;
            cur.x = search[_playerNumber].front().x;
            search[_playerNumber].pop();

            for (int j = 0; j < 4; j++)
            {
                next.y = cur.y + dy[j];
                next.x = cur.x + dx[j];

                if (next.y < 0 || next.y >= column || next.x < 0 || next.x >= row)
                    continue;
                if ('.' != board[next.y][next.x])
                    continue;

                board[next.y][next.x] = '0' + _playerNumber;
                search[_playerNumber].push(next);
                result[_playerNumber]++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    int tmp;
    bool IsFull = true;

    cin >> column >> row >> player;
    for (int i = 1; i <= player; i++)
        cin >> MoveCount[i];
    for (int i = 0; i < column; i++)
    {
        cin >> input;

        for (int j = 0; j < row; j++)
        {
            board[i][j] = input[j];

            if ('.' != board[i][j] && '#' != board[i][j])
            {
                tmp = board[i][j] - '0';
                search[tmp].push({ i, j });
                result[tmp]++;
            }
        }
    }

    while (1)
    {
        IsFull = true;

        for (int i = 1; i <= player; i++)
            if (!search[i].empty())
            {
                IsFull = false;
                break;
            }

        if (IsFull)
            break;

        for (int i = 1; i <= player; i++)
            BFS(i);
    }

    for (int i = 1; i <= player; i++)
        cout << result[i] << ' ';

    return 0;
}