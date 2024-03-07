/*
problem : n�� ���̸� ������ ���� S�� �����ϰ�, k��° ��Ҹ� �������� �� k��° ��Ҹ� �����ϰ� (k-1)��° ��ҿ� (k+1)��° ��Ҹ� ������ ���ϰ� �����տ� ���Ѵ�.
�̶� ���� �� �ִ� �������� �ִ밪�� ���ض�.
input : ���� S
output : �������� �ִ밪

idea
- 2��° ��Һ��� (n-1)��° ��ұ��� DFS ����� ����� (n-2)�� Ž���Ѵ�.
- Ž���� �Ϸ��ϸ� ������ �������� �������� ���� �ִ밪�� ���� ū ������ update�Ѵ�.
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool removed[10];                // �� ����� ���� ����
int InputArray[10];              // �Է¹��� ���� S
int ArrayLength = 0;               // ���� S�� ����
int Result = 0;                    // �������� �ִ밪

void DFS(int length, int sum)
{
    // ���� 1��° ��ҿ� n��° ��Ҹ� �����ϰ� ��� �����ߴٸ�
    // �������� ���� �ִ밪�� ���� ū ������ update�Ѵ�.
    if (length >= ArrayLength - 2)
    {
        Result = max(Result, sum);

        return;
    }

    // ���� ���ŵ��� �ʴ� ��� �� �ϳ��� ��� �����Ѵ�.
    for (int i = 1; i < ArrayLength - 1; i++)
    {
        if (!removed[i])
        {
            removed[i] = true;

            // ����, ������ operand�� ���Ѵ�.
            int LeftOperand, RightOperand;
            for (int j = i - 1; j >= 0; j--)
            {
                if (!removed[j])
                {
                    LeftOperand = InputArray[j];
                    break;
                }
            }
            for (int j = i + 1; j < ArrayLength; j++)
            {
                if (!removed[j])
                {
                    RightOperand = InputArray[j];
                    break;
                }
            }

            // ���� operand�� ���ϰ� �����տ� ����
            // ���� ��Ҹ� Ž���Ѵ�.
            DFS(length + 1, sum + (LeftOperand * RightOperand));

            removed[i] = false;
        }
    }
}

int main()
{
    // ���� S�� ���̿� �� ����� �Է�
    cin >> ArrayLength;
    for (int i = 0; i < ArrayLength; i++)
        cin >> InputArray[i];

    // DFS ������� Ž���� �������� �ִ밪�� ã�´�.
    DFS(0, 0);

    // ����� ���
    cout << Result;

    return 0;
}