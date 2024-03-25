/*
problem : n*m board���� *�� X�� ��ǥ�� ���� S ��ǥ���� D ��ǥ�� �̵��ϴ� �ִ� �ð��� ���ض�.
          *�� ��ǥ�� �ð��� ���� ������ ������ �� ĭ(.�� ��ǥ)�� ������Ų��.
          �̵��� �����¿�� �� �� �ִ�.
input : n*m board, ����� S, ������ D
output : S ��ǥ���� D ��ǥ�� �̵��ϴ� �ִ� �ð�

idea
- root�� S ��ǥ, level�� �̵��� �ð�, node�� �̵��� ���� ��ǥ�� ��Ÿ���� tree�� �����.
- tree�� BFS ������� Ž���Ѵ�.
- non-promising ���� : �̵��� ���� ��ǥ�� n*m board�� ���� ��, �̵��� ���� ��ǥ�� .�� ��ǥ�̸鼭 ������ ���� �� ������ ĭ�� ��,
                      �̵��� ���� ��ǥ�� *�� ĭ�̰ų� X�� ��ǥ�� ��, ���� level���� �̹� �ش� ��ǥ�� Ž������ ��
- ���� level(���� �̵� �ð�)���� �̹� Ž���� ĭ�� �� �̻� Ž������ �ʴ´�.
*/
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define BOARD_MAX_SIZE 50
using namespace std;

int Column, Row;                                // board�� column, row
char Board[BOARD_MAX_SIZE][BOARD_MAX_SIZE];     // n*m board
bool Search[BOARD_MAX_SIZE][BOARD_MAX_SIZE];    // ���� level���� ��ǥ�� Ž���ߴ��� ����
int dx[4] = { -1, 1, 0, 0 };                      // �̵� ����
int dy[4] = { 0, 0, -1, 1 };

bool Range(int x, int y);                       // ���� �˻�
bool Promising(int x, int y);                   // promising ���� �˻�
int BFS(int sx, int sy);                        // tree Ž��
void InfectWater();                             // �ֺ� ĭ���� * ��ǥ�� ����

int main()
{
    string input;
    int sx, sy;
    int res;

    // n*m board ������ ����� S �Է�
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;
        for (int j = 0; j < Row; j++)
        {
            Board[i][j] = input[j];

            if (Board[i][j] == 'S')
            {
                sx = i;
                sy = j;
                Board[i][j] = '.';
            }
        }
    }

    // tree�� BFS ������� Ž�� �� ����� ���
    res = BFS(sx, sy);
    if (-1 == res)
        cout << "KAKTUS";
    else
        cout << res;

    return 0;
}

bool Range(int x, int y)
{
    if (x < 0 || x >= Column || y < 0 || y >= Row)
        return false;
    return true;
}

bool Promising(int x, int y)
{
    // ���� �˻�
    if (!Range(x, y))
        return false;

    // ���� ĭ �˻�
    if (Board[x][y] == '*' || Board[x][y] == 'X')
        return false;

    // �湮 ���� �˻�
    if (Search[x][y])
        return false;

    // �ֺ� ĭ �˻�
    if (Board[x][y] == '.')
    {
        int nx, ny;
        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (!Range(nx, ny))
                continue;

            if (Board[nx][ny] == '*')
                return false;
        }
    }

    return true;
}

int BFS(int sx, int sy)
{
    queue<pair<int, int>> next;                // ������ Ž���� ĭ��
    int cx, cy, nx, ny;                        // ���� ��ǥ, ���� ��ǥ
    int MoveTime = 0;                            // �̵��� �ð�
    int QueueSize = 0;                           // �� level�� �ִ� node�� ����

    // root�� queue�� push
    next.push(make_pair(sx, sy));

    // Ž��
    while (!next.empty())
    {
        // queue�� ũ�⸸ŭ �ݺ�
        QueueSize = next.size();
        while (QueueSize--)
        {
            cx = next.front().first;
            cy = next.front().second;
            next.pop();

            // �������� �����ϸ� ���� level�� return
            if (Board[cx][cy] == 'D')
                return MoveTime;

            // 4���� �˻�
            for (int i = 0; i < 4; i++)
            {
                nx = cx + dx[i];
                ny = cy + dy[i];

                // promising �˻�
                if (!Promising(nx, ny))
                    continue;

                // ���� ��ǥ�� Ž�� �����ϰ�, queue�� push
                Search[nx][ny] = true;
                next.push(make_pair(nx, ny));
            }
        }
        memset(Search, 0, sizeof(Search));

        // * ��ǥ ����
        InfectWater();

        // level ����
        MoveTime++;
    }

    // ���������� �̵��� �� �����Ƿ� -1�� return
    return -1;
}

void InfectWater()
{
    queue<pair<int, int>> WaterPosition;            // *�� ĭ���� ��ġ
    int cx, cy, nx, ny;                             // ���� ��ǥ ���� ��ǥ

    // *�� ĭ���� ��� ã�´�.
    for (int i = 0; i < Column; i++)
        for (int j = 0; j < Row; j++)
            if (Board[i][j] == '*')
                WaterPosition.push(make_pair(i, j));

    // *�� ĭ���� ��ġ���� �ֺ� ĭ���� ����
    while (!WaterPosition.empty())
    {
        cx = WaterPosition.front().first;
        cy = WaterPosition.front().second;
        WaterPosition.pop();

        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            // ���� �˻�
            if (!Range(nx, ny))
                continue;

            // .�� ��ǥ�� ����
            if (Board[nx][ny] == '.')
                Board[nx][ny] = '*';
        }
    }
}