#include <iostream>
#include <queue>
using namespace std;

typedef struct _node
{
    int y;
    int x;
} Node;

int column, row;
char board[1000][1000];
bool visited_fire[1000][1000];
bool visited_human[1000][1000];
queue<Node> search_fire;
queue<Node> search_human;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int BFS()
{
    int level = 0;
    int size1, size2;
    Node cur, next;

    while (!search_human.empty() || !search_fire.empty())
    {
        size1 = search_fire.size();
        size2 = search_human.size();
        while (size1--)
        {
            cur.x = search_fire.front().x;
            cur.y = search_fire.front().y;
            search_fire.pop();

            for (int i = 0; i < 4; i++)
            {
                next.x = cur.x + dx[i];
                next.y = cur.y + dy[i];

                if (next.x < 0 || next.x >= row || next.y < 0 || next.y >= column)
                    continue;
                if (visited_fire[next.y][next.x])
                    continue;
                if ('#' == board[next.y][next.x])
                    continue;

                search_fire.push(next);
                visited_fire[next.y][next.x] = true;
            }
        }
        while (size2--)
        {
            cur.x = search_human.front().x;
            cur.y = search_human.front().y;
            search_human.pop();

            for (int i = 0; i < 4; i++)
            {
                next.x = cur.x + dx[i];
                next.y = cur.y + dy[i];

                if (next.x < 0 || next.x >= row || next.y < 0 || next.y >= column)
                    return level + 1;
                if (visited_fire[next.y][next.x])
                    continue;
                if (visited_human[next.y][next.x])
                    continue;
                if ('#' == board[next.y][next.x])
                    continue;

                search_human.push(next);
                visited_human[next.y][next.x] = true;
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

    string input;
    int res;

    cin >> column >> row;
    for (int i = 0; i < column; i++)
    {
        cin >> input;
        for (int j = 0; j < row; j++)
        {
            board[i][j] = input[j];

            if ('F' == board[i][j])
            {
                search_fire.push({ i, j });
                board[i][j] = '.';
                visited_fire[i][j] = true;
            }
            else if ('J' == board[i][j])
            {
                search_human.push({ i, j });
                board[i][j] = '.';
                visited_human[i][j] = true;
            }
        }
    }

    res = BFS();
    if (-1 == res)
        cout << "IMPOSSIBLE";
    else
        cout << res;

    return 0;
}