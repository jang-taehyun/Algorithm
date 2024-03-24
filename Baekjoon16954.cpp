/*
problem : 8*8 board���� (7, 0)�������� ������ (0, 7)���� �̵��Ϸ��� �Ѵ�.
          board���� ��(#�� ĭ)�� 1�ʸ��� �Ʒ� ������ �������� �Ʒ� ���� ���ٸ� �������.
          player�� �����¿� �Ǵ� �밢������ �� ĭ �̵��ϰų� ���� ��ġ�� �� ���� �� �ְ�, �� ĭ���θ� �̵��� �� �ִ�.
          1�� ���� player�� ���� �̵��ϰ� ������ ���� �̵��Ѵ�.
          ���� player�� �ִ� ĭ���� �̵��ϸ� player�� ���̻� �̵��� �� ����.
          8*8 board���� player�� (7, 0)�������� ������ (0, 7)���� �̵��� �� �ִ��� ���ض�.
input : 8*8 board�� ����
output : 8*8 board���� player�� (7, 0)�������� ������ (0, 7)���� �̵��� �� �ִ��� ���ض�.

idea
- root�� (7, 0), level�� �̵��� ĭ�� Ƚ��(Ž�� �ð�), node�� �̵��� ���� player�� ��ġ�� ��Ÿ���� tree�� �����.
- tree�� BFS ������� Ž���Ѵ�.
- �� level�� ��� Ž���ϸ� board�� ���¸� �ٲ۴�.
- node�� Ž���ϱ� ���� ���� node�� ��ġ�� ������ Ȯ���Ѵ�. ���̸� �̵����� �ʴ´�.
*/
#include <iostream>
#include <queue>
#include <string>
#define BOARD_SIZE 8
#define START_X 7
#define START_Y 0
#define END_X 0
#define END_Y 7
#define WALL_MOVE_X 1
#define WALL_MOVE_Y 0
using namespace std;

char Board[BOARD_SIZE][BOARD_SIZE];            // board�� ����
int dx[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };    // �̵� ����
int dy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
queue<pair<int, int>> WallPosition;            // ������ ��ġ

// ���� �˻�
bool Range(int x, int y);

// ����, �� �˻�
bool Promising(int x, int y);

// tree Ž��
bool BFS();

int main()
{
    string input;

    // 8*8 board�� �Է��ϰ� ���� ��ġ�� queue�� �ִ´�
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cin >> input;
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            Board[i][j] = input[j];

            if (Board[i][j] == '#')
                WallPosition.push(make_pair(i, j));
        }
    }

    // tree�� BFS ������� Ž�� �� ����� ���
    if (BFS())
        cout << 1;
    else
        cout << 0;

    return 0;
}

bool Range(int x, int y)
{
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE)
        return false;
    return true;
}

bool Promising(int x, int y)
{
    if (!Range(x, y))
        return false;
    if (Board[x][y] == '#')
        return false;
    return true;
}

bool BFS()
{
    queue<pair<int, int>> next;                // ������ Ž���� node��
    int cx, cy, nx, ny;                        // ���� ��ġ, ���� ��ġ
    int QueueSize;                             // queue�� ũ��(�� level�� �ִ� node�� ����)
    int MoveWallCount;                         // ������ ���� ����

    // �������� queue�� push
    next.push(make_pair(START_X, START_Y));

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

            // ���� ��ġ�� ������ �˻�
            if (Board[cx][cy] == '#')
                continue;

            // �������� �����ߴٸ� true�� return
            if (END_X == cx && END_Y == cy)
                return true;

            // 9���� ���� Ž��
            for (int i = 0; i < 9; i++)
            {
                nx = cx + dx[i];
                ny = cy + dy[i];

                // ����, �� �˻�
                if (!Promising(nx, ny))
                    continue;

                // ���� ��ġ�� queue�� push
                next.push(make_pair(nx, ny));
            }
        }

        // ������ �Ʒ� ĭ���� �̵�
        QueueSize = WallPosition.size();
        MoveWallCount = QueueSize;

        // ���� ���� ��ġ�� �� ĭ���� �����.
        while (QueueSize--)
        {
            cx = WallPosition.front().first;
            cy = WallPosition.front().second;
            WallPosition.pop();
            Board[cx][cy] = '.';

            nx = cx + WALL_MOVE_X;
            ny = cy + WALL_MOVE_Y;

            // �Ʒ��� ���� ���ٸ� ���� ���ش�.
            if (!Range(nx, ny))
                MoveWallCount--;
            else
                WallPosition.push(make_pair(cx, cy));
        }

        // �̵��� ���� ��ġ�� ������ �����.
        while (MoveWallCount--)
        {
            cx = WallPosition.front().first;
            cy = WallPosition.front().second;
            WallPosition.pop();

            nx = cx + WALL_MOVE_X;
            ny = cy + WALL_MOVE_Y;

            WallPosition.push(make_pair(nx, ny));
            Board[nx][ny] = '#';
        }
    }

    // ����� ã�� �������Ƿ� false ��ȯ
    return false;
}