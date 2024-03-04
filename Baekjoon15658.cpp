/*
problem : n���� ���� �ִ� 4n���� �����ڰ� �־����� ��, ������ ������ �ٲ��� �ʰ� ���� ���̿� �����ڸ� �־� ���� �� �ִ� ������ �ִ밪�� �ּҰ��� ���ض�.
input : n���� ��, �ִ� 4n���� ������
output : ������ ������ �ٲ��� �ʰ� ���� ���̿� �����ڸ� �־� ���� �� �ִ� ������ �ִ밪, �ּҰ�

idea
- brute force�� �̿��� �����ڵ��� (n-1)�� �����Ѵ�.
- ������ �ϼ��Ǹ� ������ ����� �ּڰ��� �ִ밪�� update�Ѵ�.
*/
#include <iostream>
using namespace std;

int ArrayLength;                        // ������ ����
int InputArray[11];                     // �Է¹��� ����(n���� ��)
int OperationCount[4];                  // ����� �� �ִ� �������� ����
                                        // 0 : +, 1 : -, 2 : *, 3 : /
int MaximumResult = -1000000000;        // ���� �� �ִ� ������ �ִ밪
int MinimumResult = 1000000000;         // ���� �� �ִ� ������ �ּҰ�

void Bruteforce(int Length, int ComputeResult)
{
    // ������ �ϼ��ߴٸ� �ּڰ��� �ִ밪 update
    if (Length >= ArrayLength - 1)
    {
        if (ComputeResult > MaximumResult)
            MaximumResult = ComputeResult;
        if (ComputeResult < MinimumResult)
            MinimumResult = ComputeResult;

        return;
    }

    // ����� �� �ִ� ������ �� �ϳ��� ��� ������ �Ѵ�.
    for (int i = 0; i < 4; i++)
    {
        if (OperationCount[i])
        {
            OperationCount[i]--;
            switch (i)
            {
            case 0:
                Bruteforce(Length + 1, ComputeResult + InputArray[Length + 1]);
                break;
            case 1:
                Bruteforce(Length + 1, ComputeResult - InputArray[Length + 1]);
                break;
            case 2:
                Bruteforce(Length + 1, ComputeResult * InputArray[Length + 1]);
                break;
            case 3:
                Bruteforce(Length + 1, ComputeResult / InputArray[Length + 1]);
                break;
            }
            OperationCount[i]++;
        }
    }
}

int main()
{
    // n���� ���ڿ� �������� ���� �Է�
    cin >> ArrayLength;
    for (int i = 0; i < ArrayLength; i++)
        cin >> InputArray[i];
    for (int i = 0; i < 4; i++)
        cin >> OperationCount[i];

    // brute force�� �̿��� �����ڵ��� (n-1)�� �����Ͽ� ���� ������ �ִ밪�� �ּҰ��� ���Ѵ�.
    Bruteforce(0, InputArray[0]);

    // ����� ���
    cout << MaximumResult << '\n' << MinimumResult;

    return 0;
}