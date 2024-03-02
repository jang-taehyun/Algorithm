/*
Problem : n���� ���ڿ� (n-1)���� �����ڰ� �־����� ��, �־��� ������ ������ �ٲ��� �ʰ� ���� �� �ִ� ������ �ִ밪�� �ּڰ��� ���ض�.
Input : n���� ����, (n-1)���� ������
Output : ������ �ִ밪, �ּҰ�

Idea
- �׻� ���Ǵ� ������ -10^9 ~ 10^9 �����̹Ƿ� long long������ �ڷ����� ����
- �� ������ ������� ���� Ƚ���� ��Ÿ���� UsingCount�� ���� �� �����ڰ� ���� Ƚ���� ǥ��
- DFS ����� ���� ������ �ϼ��Ͽ� �ִ밪�� �ּҰ��� ���Ѵ�.
*/
#include <iostream>
#define MAX 9999999999
#define MIN -9999999999
using namespace std;

int InputNumberCount;               // �Էµ� ���ڵ��� ����
long long InputNumber[11];          // �Էµ� ���ڵ�

int AbleUsingCount[4];              // �� �����ڵ��� ����� �� �ִ� Ƚ��
                                    // 0 : +, 1 : -, 2 : *, 3 : /
int UsingCount[4];                  // �� �����ڵ��� ������� ���� Ƚ��
int Operation[10];                  // ������� ���õ� ������

long long MaximumNumber = MIN;        // ������� ���� ���� �� �ִ밪
long long MinimumNumber = MAX;        // ������� ���� ���� �� �ּڰ�

void DFS(int Length)
{
    // ���� ������ �ϼ��Ǿ��ٸ�, ������ ����ϰ� �ּҰ��� �ִ밪 update
    if (Length >= InputNumberCount - 1)
    {
        long long tmp = InputNumber[0];

        for (int i = 0; i < Length; i++)
        {
            switch (Operation[i])
            {
            case 0:
            {
                tmp = (tmp + InputNumber[i + 1]);
            }
            break;
            case 1:
            {
                tmp = (tmp - InputNumber[i + 1]);
            }
            break;
            case 2:
            {
                tmp = (tmp * InputNumber[i + 1]);
            }
            break;
            case 3:
            {
                // ���� ������ ������ ��
                if (tmp < 0)
                {
                    // ��� ����� ����� �ְ�
                    tmp *= (long long)(-1);

                    // ������ ����� ��, -1�� ���Ѵ�.
                    tmp = (tmp / InputNumber[i + 1]);
                    tmp *= (long long)(-1);
                }
                else
                    tmp = (tmp / InputNumber[i + 1]);
            }
            break;
            }
        }

        if (tmp > MaximumNumber)
            MaximumNumber = tmp;
        if (tmp < MinimumNumber)
            MinimumNumber = tmp;

        return;
    }

    // �����ڵ��� ����.
    for (int i = 0; i < 4; i++)
    {
        if (UsingCount[i] < AbleUsingCount[i])
        {
            UsingCount[i]++;
            Operation[Length] = i;
            DFS(Length + 1);
            UsingCount[i]--;
        }
    }
}

int main()
{
    // �Էµ� ������ ������ ���ڸ� �Է¹ް�, ����� �� �ִ� �������� ������ �Է¹޴´�.
    cin >> InputNumberCount;
    for (int i = 0; i < InputNumberCount; i++)
        cin >> InputNumber[i];
    for (int i = 0; i < 4; i++)
        cin >> AbleUsingCount[i];

    // DFS ����� ���� ������ �ϼ��ϰ� �ִ밪�� �ּڰ��� ���Ѵ�.
    DFS(0);

    // ����� ���
    cout << MaximumNumber << '\n' << MinimumNumber;

    return 0;
}