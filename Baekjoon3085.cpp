/*
problem : ������ n*n���� ä������ ��, ������ ���� �ٸ� ������ �� ĭ�� ��� ��ȯ �� �� ��� ���� ������ �̷���� ���� �� ���� �κ��� ��� �Դ� ��� �� ���� �� �ִ� ������ �ִ� ������ ���ض�
input : ������ ũ�� n, ���忡 ä�����ִ� ������ ���� color
output : ���ǿ� ���� ���� �� �ִ� ������ �ִ� ����

idea : ���� �������� �ٲ� �� ���带 �˻��ϰ�, ���� �������� �ٲ� �� ���带 �˻��Ѵ�.
*/
#include <iostream>
using namespace std;

// ������ ũ�� n
int n;
// ������ ���� ����
char board[51][51];
// ���ǿ� ���� ���� �� �ִ� ������ �ִ� ���� max
int res;

int Max(int x, int y) { return x > y ? x : y; }

void SwapCandy(char& x, char& y)
{
    char temp = x;
    x = y;
    y = temp;
}

void Check()
{
    // ���� ������ ����
    int count;
    // ���� ���� ������ ����
    char color;

    // �� �������� �˻�
    for (int column = 0; column < n; column++)
    {
        // �ʱⰪ ����
        count = 1;
        color = board[column][0];

        // �� �������� ������ ���ٸ� +1�� �ϰ�, �ٸ��� count�� 1�� �ǵ����� ���� ���� ������ color�� ���� Ž���ϰ� �ִ� ������ ����� ����
        for (int row = 1; row < n; row++)
        {
            if (board[column][row] == color)
                count++;
            else
            {
                count = 1;
                color = board[column][row];
            }

            // res ������Ʈ
            res = Max(res, count);
        }
    }

    // �� �������� �˻�
    for (int row = 0; row < n; row++)
    {
        // �ʱⰪ ����
        count = 1;
        color = board[0][row];

        // �� �������� ������ ���ٸ� +1�� �ϰ�, �ٸ��� count�� 1�� �ǵ����� ���� ���� ������ color�� ���� Ž���ϰ� �ִ� ������ ����� ����
        for (int column = 1; column < n; column++)
        {
            if (board[column][row] == color)
                count++;
            else
            {
                count = 1;
                color = board[column][row];
            }

            // res ������Ʈ
            res = Max(res, count);
        }
    }
}

int main()
{
    // ������ ũ�� n�� ���忡 ä���� �ִ� ������ ���� �Է�
    cin >> n;
    for (int column = 0; column < n; column++)
        for (int row = 0; row < n; row++)
            cin >> board[column][row];

    // ���� �������� ������ ��ġ�� �ٲ� �� ���带 �˻�
    for (int column = 0; column < n; column++)
    {
        for (int row = 0; row < n - 1; row++)
        {
            SwapCandy(board[column][row], board[column][row + 1]);
            Check();
            SwapCandy(board[column][row], board[column][row + 1]);
        }
    }

    // ���� �������� ������ ��ġ�� �ٲ� �� ���� �˻�
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < n - 1; column++)
        {
            SwapCandy(board[column][row], board[column + 1][row]);
            Check();
            SwapCandy(board[column][row], board[column + 1][row]);
        }
    }

    // ����� ���
    cout << res;

    return 0;
}