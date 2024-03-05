/*
problem : board ���� 2���� ������ 4���� ��ư�� ���� ��, ���� �ϳ��� ����߸��� ���� ��ư�� ����� �ϴ� �ּ� Ƚ���� ���ض�.
input : board�� �� ĭ�� ���� ����, ���� 2���� ��ġ
output : ���� 1���� ����߸��� ���� �������ϴ� ��ư�� �ּ� Ƚ��

idea
- DFS ����� �̿��� ��ư�� ������, ��ư�� ���� �Ŀ� �� ���� ������ board�� ���� �������� Ȯ���Ѵ�.
  0 : ��� ����
  1 : ������� update
  2 : Ž�� �ߴ�
- ���� ������� 10ȸ �̻��� ���, -1�� ����Ѵ�.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#define BOUND 10
using namespace std;

char board[20][20];                        // board�� ����
                                           // . : �� ĭ / # : ��
int Column, Row;                           // board�� column, Row
int dx[4] = { 0, 0, -1, 1 };                 // ���� �� �ִ� 4���� ��ư
int dy[4] = { 1, -1, 0, 0 };
int Result = 99999999;                       // ��ư�� ������ �ּ� Ƚ��

bool IsRange(int px, int py) { return (0 <= px && px < Column && 0 <= py && py < Row); }

void DFS(int cx1, int cy1, int cx2, int cy2, int direction, int ButtonCount)
{
    // ���� ��ư�� ������ ã�Ҵ� Ƚ������ �� ���� ������ �� �̻� Ž������ �ʴ´�.
    if (ButtonCount > Result)
        return;

    // ���� 10ȸ �̻� ������ ������� update�Ѵ�.
    if (ButtonCount > BOUND)
    {
        Result = min(Result, ButtonCount);
        return;
    }

    int nx1 = cx1 + dx[direction];
    int ny1 = cy1 + dy[direction];
    int nx2 = cx2 + dx[direction];
    int ny2 = cy2 + dy[direction];

    // ���� ������ �� �� ���������� Ȯ��
    // 2�� ��� ������ ���
    if (!IsRange(nx1, ny1) && !IsRange(nx2, ny2))
        return;
    // 1���� ������ ���
    else if ((IsRange(nx1, ny1) && !IsRange(nx2, ny2)) || (!IsRange(nx1, ny1) && IsRange(nx2, ny2)))
    {
        Result = min(Result, ButtonCount);
        return;
    }

    // �̵��� ��ġ�� ���̶�� ���� �����Ѵ�.
    if (board[nx1][ny1] == '#')
    {
        nx1 = cx1;
        ny1 = cy1;
    }
    if (board[nx2][ny2] == '#')
    {
        nx2 = cx2;
        ny2 = cy2;
    }

    // DFS�� �̿��� ��ư�� �� ������.
    for (int i = 0; i < 4; i++)
    {
        DFS(nx1, ny1, nx2, ny2, i, ButtonCount + 1);
    }
}

int main()
{
    string input;
    int CoinPosX[2];
    int CoinPosY[2];

    // board�� Column�� Row ������ �Է¹ް�, board�� ���¿� ���� 2���� ��ġ�� �Է¹޴´�.
    int index = 0;
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;

        for (int j = 0; j < Row; j++)
        {
            board[i][j] = input[j];

            if (board[i][j] == 'o')
            {
                CoinPosX[index] = i;
                CoinPosY[index] = j;
                index++;
            }
        }
    }

    // DFS Ž���� ���� ��ư�� ������ Ƚ���� ���Ѵ�.
    for (int i = 0; i < 4; i++)
    {
        DFS(CoinPosX[0], CoinPosY[0], CoinPosX[1], CoinPosY[1], i, 1);
    }

    // ����� ���
    if (Result > BOUND)
        Result = -1;
    cout << Result;

    return 0;
}