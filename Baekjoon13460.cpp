/*
problem : n*m board�� ���� ������ �Ķ� ������ ��ġ�� �־����� ��, ���� ������ ���ۿ� ���� �� �ֵ��� ����̴� Ƚ���� �ּҰ��� ���ض�.
input : n*m board, ���� ������ ��ġ, �Ķ� ������ ��ġ
output : board���� ���� ������ ���ۿ� ���� �� ����̴� Ƚ���� �ּҰ�

idea
- �����¿� �� ����� ������ �����ϰ� ������ ���� �����ų� ������ ���������� �̵��Ѵ�.
- ������ �̵��� ������ ������ ��ġ�� update�Ѵ�.
- �Ķ� ������ ���� ��ȿ ó���� �Ѵ�.
- �� ���� ������ ��� ���ۿ� ���� ������ ������ ������ ������ ���ϰ� ���� ������ �ݺ��Ѵ�.
- �� ������ BFS Ž���� �̿��� Ž���Ѵ�.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

char Board[10][10];                    // m*n board�� ����
int Column, Row;                       // board�� column, row ����
int MinimumTiltCount;                  // ����̴� �ּҰ�
int dx[4] = { 0, 0, 1, -1 };           // board�� ����̴� ����
int dy[4] = { -1, 1, 0, 0 };
bool visited[10][10][10][10];          // �ش� ��ǥ�� �湮�ߴ��� ����

typedef struct _p
{
    int rx;
    int ry;
    int bx;
    int by;
    int cnt;
} BallPoints;

int MoveBall(int* x, int* y, int dir)
{
    int MoveCount = 0;

    // ���̳� ������ ���������� ��� �̵�
    while (Board[*x + dx[dir]][*y + dy[dir]] != '#' &&
        Board[*x][*y] != 'O')
    {
        *x += dx[dir];
        *y += dy[dir];
        MoveCount++;
    }

    // ���� �̵��� Ƚ���� return
    return MoveCount;
}

int BFS(int rx, int ry, int bx, int by)
{
    int crx, cry, cbx, cby;                    // �������� �Ķ����� ���� ��ġ
    int nrx, nry, nbx, nby;                    // �������� �Ķ����� ���� ��ġ
    int cnt = 0;                                 // ����� Ƚ��
    queue<BallPoints> Search;                  // ������ Ž���� ������ ��ġ
    int RedBallMoveCount, BlueBallMoveCount;   // �������� �Ķ����� ������ ĭ�� ����

    // ó�� ��ġ�� queue�� �ְ�, �湮 ó��
    Search.push({ rx, ry, bx, by, cnt });
    visited[rx][ry][bx][by] = true;

    while (!Search.empty())
    {
        // Ž���� ������ ��ġ�� ������.
        crx = Search.front().rx;
        cry = Search.front().ry;
        cbx = Search.front().bx;
        cby = Search.front().by;
        cnt = Search.front().cnt;
        Search.pop();

        // ���� 10ȸ �ʰ��� ����δٸ� loop�� ����
        if (cnt >= 10)
            break;

        // 4������ ��� Ž���� ������ ���� ��ġ�� ���Ѵ�.
        for (int i = 0; i < 4; i++)
        {
            nrx = crx;
            nry = cry;
            nbx = cbx;
            nby = cby;

            RedBallMoveCount = MoveBall(&nrx, &nry, i);
            BlueBallMoveCount = MoveBall(&nbx, &nby, i);

            // �̹� �湮�� ��ǥ���̶�� ���� ��ġ���� �ľ��Ѵ�.
            if (visited[nrx][nry][nbx][nby])
                continue;

            // ���� �Ķ����� ���ۿ� ���� �ٸ� ��ġ Ž��
            if (Board[nbx][nby] == 'O')
                continue;

            // ���� �������� ���ۿ� ���� ����� Ƚ���� return
            if (Board[nrx][nry] == 'O')
                return cnt + 1;

            // ���� �� ���� ��ġ�� ���ٸ�, �� ���� ������ ���� �� ĭ �ڷ� �̵�
            if (nrx == nbx && nry == nby)
            {
                if (RedBallMoveCount > BlueBallMoveCount)
                {
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else
                {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            // ������ ��ġ�� queue�� push
            Search.push({ nrx, nry, nbx, nby, cnt + 1 });
            visited[nrx][nry][nbx][nby] = true;
        }
    }

    return -1;
}

int main()
{
    string input;
    int rx, ry, bx, by;

    // m*n board�� ���� �Է�
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;

        for (int j = 0; j < Row; j++)
        {
            Board[i][j] = input[j];

            // ���� ������ �����ٸ� ������ ��ġ�� ����ϰ� ��η� ����
            if (Board[i][j] == 'R')
            {
                rx = i;
                ry = j;
                Board[i][j] = '.';
            }
            if (Board[i][j] == 'B')
            {
                bx = i;
                by = j;
                Board[i][j] = '.';
            }
        }
    }

    // 4���� ���� �� �ϳ��� ������ board�� ����̰� ������ �̵�
    // �� �� ������� ���
    cout << BFS(rx, ry, bx, by);

    return 0;
}