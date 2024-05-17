#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

typedef struct _node
{
    int y;
    int x;
} Node;

int column, row;
bool visited_human[1000][1000];
bool visited_fire[1000][1000];
char board[1000][1000];
queue<Node> search_fire;
queue<Node> search_human;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void init()
{
    memset(board, 0, sizeof(board));
    memset(visited_human, false, sizeof(visited_human));
    memset(visited_fire, false, sizeof(visited_fire));
    search_fire = queue<Node>();
    search_human = queue<Node>();
}

int BFS()
{
    Node cur, next;
    int size1, size2;
    int level = 0;

    while (!search_fire.empty() || !search_human.empty())
    {
        size1 = search_fire.size();
        size2 = search_human.size();

        while (size1--)
        {
            cur.y = search_fire.front().y;
            cur.x = search_fire.front().x;
            search_fire.pop();

            for (int i = 0; i < 4; i++)
            {
                next.y = cur.y + dy[i];
                next.x = cur.x + dx[i];

                if (next.x < 0 || next.x >= row || next.y < 0 || next.y >= column)
                    continue;
                if (visited_fire[next.y][next.x])
                    continue;
                if ('#' == board[next.y][next.x])
                    continue;

                visited_fire[next.y][next.x] = true;
                search_fire.push(next);
            }
        }
        while (size2--)
        {
            cur.y = search_human.front().y;
            cur.x = search_human.front().x;
            search_human.pop();

            for (int i = 0; i < 4; i++)
            {
                next.y = cur.y + dy[i];
                next.x = cur.x + dx[i];

                if (next.x < 0 || next.x >= row || next.y < 0 || next.y >= column)
                    return level + 1;
                if (visited_fire[next.y][next.x])
                    continue;
                if (visited_human[next.y][next.x])
                    continue;
                if ('#' == board[next.y][next.x])
                    continue;

                visited_human[next.y][next.x] = true;
                search_human.push(next);
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

    int test, res;
    string input;

    cin >> test;

    while (test--)
    {
        init();

        cin >> row >> column;
        for (int i = 0; i < column; i++)
        {
            cin >> input;
            for (int j = 0; j < row; j++)
            {
                board[i][j] = input[j];

                if ('@' == board[i][j])
                {
                    board[i][j] = '.';
                    visited_human[i][j] = true;
                    search_human.push({ i, j });
                }
                else if ('*' == board[i][j])
                {
                    board[i][j] = '.';
                    visited_fire[i][j] = true;
                    search_fire.push({ i, j });
                }
            }
        }

        res = BFS();
        if (-1 == res)
            cout << "IMPOSSIBLE" << '\n';
        else
            cout << res << '\n';
    }

    return 0;
}