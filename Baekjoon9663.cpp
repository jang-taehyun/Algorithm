/*
Problem : n*n ü���ǿ� n���� ���� ���� ������ �� ���� ��ġ�ϴ� ����� ���� ���ض�.
input : n
output : n���� ���� ���� ������ �� ���� ��ġ�ϴ� ����� ��

idea
- n*n ü���ǿ� n���� ���� ���� ����� row�� level, node�� (column, row)�� state space tree�� �����Ѵ�.
- ���� row���� ���� 1���� ���� �� �ִ� ������� �����Ͽ� DFS ������� Ž���Ѵ�.
- ���� ü���ǿ� ���� ����, ���� ü���ǿ� ����, �밢�� ���� Ȯ���� ���� ������ �� �ִ��� ������ �Ǵ��Ѵ�.
- ���� ���� ������ �� �ִٸ�, Ž���� �ߴ��Ѵ�.
*/
#include <iostream>
#include <cmath>
using namespace std;

int BoardLength;                 // ü������ �� ���� ����
int Result = 0;                    // n*n ü���ǿ� n���� ���� ���� ������ �� ���� ��ġ�ϴ� ����� ��
int QueenRowPosition[15];        // ���� queen���� ������ ��ġ
                                 // index : column, value : row

// ���� ü���ǿ� ����, �밢�� ���� queen�� 2�� �̻� ������ �ִ��� Ȯ��
bool IsPromising(int CurrentColumn)
{
    for (int i = 0; i < CurrentColumn; i++)
    {
        // ���� ���� ���� �ְų�, ���� �밢���� �ִٸ� false ��ȯ
        if ((QueenRowPosition[i] == QueenRowPosition[CurrentColumn]) || (abs(QueenRowPosition[i] - QueenRowPosition[CurrentColumn]) == CurrentColumn - i))
            return false;
    }

    return true;
}

// �� ���� column������ queen�� 1���� �����鼭 state space tree�� DFS ������� Ž��
void DFS(int CurrentColumn)
{
    // ���� board�� ���°� promising ���� Ȯ��
    if (IsPromising(CurrentColumn))
    {
        // ���� n���� queen�� ��� ���Ҵٸ�, ������� 1 ����
        if (CurrentColumn >= BoardLength - 1)
        {
            Result++;
            return;
        }

        // ���� column�� queen�� 1���� ���´�.
        for (int i = 0; i < BoardLength; i++)
        {
            QueenRowPosition[CurrentColumn + 1] = i;
            DFS(CurrentColumn + 1);
        }
    }
}

int main()
{
    // ü���� �� ���� ���̸� �Է�
    cin >> BoardLength;

    // state space tree�� DFS ������� Ž��
    // �� ���� column������ queen�� 1���� ���´�.
    for (int i = 0; i < BoardLength; i++)
    {
        QueenRowPosition[0] = i;
        DFS(0);
    }

    // ����� ���
    cout << Result;

    return 0;
}