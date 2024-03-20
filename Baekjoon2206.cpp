/*
problem : n*m board���� ���� �ϳ� �μ��ų�, �μ��� �ʰ� (1, 1)���� ������ (n ,m)���� ���� �ִ� ��θ� ���ض�.
input : n*m board
output : ���� �ϳ� �μ��ų�, �μ��� �ʰ� (1, 1)���� ������ (n, m)���� ���� �ִ� ���

idea
- root�� ������(1, 1), level�� �̵��� ĭ�� ����, node�� �����¿�� �̵��� ���� ��ǥ�� ������ ���� �μ����� ���θ� ��Ÿ���� tree�� �����.
- �ִ� ��δ� tree�� BFS Ž���Ͽ� ���Ѵ�.
- Ž���� �� �̹� Ž���� ĭ�� �� Ž������ �ʴ´�.
- ���� ������ ���� �μ��� �ʾҴٸ�, ���� ������ �� �� �� �μ���.
- ���� ������ ���� �μ� ���� �ִٸ�, ���� ������ �� �μ��� �ʴ´�.

�����ڷ� : https://kscodebase.tistory.com/66
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#define BOUND 1000
using namespace std;

int Column, Row;                // board�� ����, ���� ����
int Board[BOUND][BOUND];        // board
bool Search[BOUND][BOUND][2];   // ��ġ�� Ž�� ����
                                // 0 : ���� �μ��� �ʾ��� ��, 1 : ���� �μ��� ��
int dx[4] = { 0, 0, 1, -1 };      // �̵� ����
int dy[4] = { -1, 1, 0, 0 };

// node�� ���� ���¸� ��Ÿ���� �ڷ���
typedef struct _state
{
    int x;
    int y;
    bool BreakWall;
} NodeState;

// ����, Ž�� ���� �˻�
bool IsPromising(int _x, int _y, bool IsBreakWall);

// �ִ� ��� ���ϱ�
int BFS();

int main()
{
    string input;

    // board�� ���� �Է�
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;

        for (int j = 0; j < Row; j++)
            Board[i][j] = input[j] - '0';
    }

    // BFS Ž�� ���� �� ��� ���
    cout << BFS();

    return 0;
}

bool IsPromising(int _x, int _y, bool IsBreakWall)
{
    if (_x < 0 || _x >= Column || _y < 0 || _y >= Row)
        return false;

    if (Search[_x][_y][IsBreakWall])
        return false;

    return true;
}

int BFS()
{
    queue<NodeState> next;                 // ������ Ž���� ĭ
    int MoveCount = 1;                       // �̵��� Ƚ��
    int QueueSize;                         // �� level�� ũ��
    int CurX, CurY, NextX, NextY;          // ���� ��ġ, ���� ��ġ
    bool CurrentState, NextState;          // ���� node�� ����, ���� node�� ����

    // ������(1, 1)�� Ž�� �����ϰ� queue�� �ִ´�.
    Search[0][0][0] = true;
    next.push({ 0, 0, 0 });

    while (!next.empty())
    {
        // ���� queue�� ũ�⸸ŭ �ݺ�
        QueueSize = next.size();
        while (QueueSize--)
        {
            // queue���� node�� �ϳ� ������ Ž��
            CurX = next.front().x;
            CurY = next.front().y;
            CurrentState = next.front().BreakWall;
            next.pop();

            // �������� �����ϸ� ���� level(�̵��� ĭ�� Ƚ��)�� return
            if (CurX == Column - 1 && CurY == Row - 1)
                return MoveCount;

            // 4���� ���� �� ���ǿ� �´� ĭ�� ã�� queue�� �ִ´�.
            for (int dir = 0; dir < 4; dir++)
            {
                NextX = CurX + dx[dir];
                NextY = CurY + dy[dir];
                NextState = CurrentState;

                if (!IsPromising(NextX, NextY, NextState))
                    continue;

                // ���� �ƴ� ���
                if (!Board[NextX][NextY])
                {
                    Search[NextX][NextY][NextState] = true;
                    next.push({ NextX, NextY, NextState });
                }

                // ���̸鼭, ���� ���� �� ���� ���� ���
                if (Board[NextX][NextY] && !NextState)
                {
                    Search[NextX][NextY][NextState] = true;
                    NextState = 1;
                    Search[NextX][NextY][NextState] = true;
                    next.push({ NextX, NextY, NextState });
                }
            }
        }

        // level ����
        MoveCount++;
    }

    // ����� ã�� �������Ƿ� -1�� return
    return -1;
}