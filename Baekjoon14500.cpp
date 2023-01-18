/*
problem : n*m ĭ���� ��Ʈ�ι̳밡 ���� ĭ�� ���� �ִ밡 �Ǵ� ����� ���� ���ض�.
input : column n, row m, n*m ĭ�� ���� ����
output : ��Ʈ�ι̳밡 ���� Ų�� ���� �ִ밡 �Ǵ� ����� ��

idea : ��� �������� DFS ����� �̿��� depth�� 4�� ��� Ž���� �����ϰ� ���� ã�� �� �� ���� ū ������ Ȯ���Ѵ�.
��, ��, ��, �� ����� ���� ����� �� 5������ ������� Ž���� �� �� ���� ū ���� ã�´�.
*/
#define MAX_SIZE 500
#define END_DEPTH 4
#include <iostream>
#include <cstring>
using namespace std;

int board[MAX_SIZE][MAX_SIZE];
bool isVisited[MAX_SIZE][MAX_SIZE];
int MoveColumn[4] = { 0, 0, 1, -1 };
int MoveRow[4] = { 1, -1, 0, 0 };

int Max(int x, int y) { return x > y ? x : y; }

void DFS(int column, int row, int depth, int sum, int* result, const int boundColumn, const int boundRow)
{
    // ���� ��ġ �湮
    isVisited[column][row] = true;

    // depth�� 4�̸� ����� ���� ���� �� ��
    if (depth >= END_DEPTH)
    {
        *result = Max(*result, sum);
        return;
    }

    // ���� ��ġ Ž��
    for (int i = 0; i < 4; i++)
    {
        // ���� ��ġ ����
        int NextPointColumn = column + MoveColumn[i];
        int NextPointRow = row + MoveRow[i];

        // ���� ��ġ�� ���� ���� ó��
        if (NextPointColumn >= boundColumn || NextPointRow >= boundRow || NextPointColumn < 0 || NextPointRow < 0)
            continue;
        if (isVisited[NextPointColumn][NextPointRow])
            continue;

        // ���� ��ġ �湮
        DFS(NextPointColumn, NextPointRow, depth + 1, sum + board[NextPointColumn][NextPointRow], result, boundColumn, boundRow);

        // �湮 �� �ٽ� ���󺹱�
        isVisited[NextPointColumn][NextPointRow] = false;
    }
}

// �� ���
void Shape1(int column, int row, int* result)
{
    int res = board[column][row] + board[column][row + 1] + board[column][row + 2] + board[column - 1][row + 1];
    *result = Max(*result, res);
}

// �� ���
void Shape2(int column, int row, int* result)
{
    int res = board[column][row] + board[column][row + 1] + board[column][row + 2] + board[column + 1][row + 1];
    *result = Max(*result, res);
}

// �� ���
void Shape3(int column, int row, int* result)
{
    int res = board[column][row] + board[column + 1][row] + board[column + 2][row] + board[column + 1][row + 1];
    *result = Max(*result, res);
}

// �� ���
void Shape4(int column, int row, int* result)
{
    int res = board[column][row] + board[column - 1][row + 1] + board[column][row + 1] + board[column + 1][row + 1];
    *result = Max(*result, res);
}

int main()
{
    // column n, row m
    int n = 0, m = 0;
    // �ִ밪 max
    int max = 0;

    // column, row, board �Է�
    cin >> n >> m;
    for (int column = 0; column < n; column++)
        for (int row = 0; row < m; row++)
            cin >> board[column][row];

    // 5���� ��쿡 ���� ��� ��ġ�� Ž���ϸ鼭 �ִ밪 ã��
    for (int column = 0; column < n; column++)
    {
        for (int row = 0; row < m; row++)
        {
            // �湮 ���� �ʱ�ȭ
            memset(isVisited, false, sizeof(isVisited));

            // 5���� ��츦 ��� Ž��
            DFS(column, row, 1, board[column][row], &max, n, m);
            if (column - 1 >= 0 && row + 2 < m)
                Shape1(column, row, &max);
            if (column + 1 < n && row + 2 < m)
                Shape2(column, row, &max);
            if (column + 2 < n && row + 1 < m)
                Shape3(column, row, &max);
            if (column + 1 < n && column - 1 >= 0 && row + 1 < m)
                Shape4(column, row, &max);
        }
    }

    // ����� ���
    cout << max;

    return 0;
}