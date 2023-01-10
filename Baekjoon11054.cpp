/*
problem : ���� S�� ���� �� ������� ������ ���̸� ���ض�
input : ���� S�� ���� n, ���� s�� ��� value
output : ���� S�� ���� �� ������� ������ ����

idea
- ���� S�� 1��° ��Һ��� ������ n��° ��ұ��� ���� �� �����ϴ� �κ� ������ ���Ѵ�.
- ���� S�� n��° ��Һ��� ������ 1��° ��ұ��� ���� �� �����ϴ� �κ� ������ ���Ѵ�.
- �� ��Ҹ� ���� �� 1�� �A��.
- �����
  - dp_increase[i] : i��° ��Ҹ� �� ���� �����ϸ鼭, 0���� i��° ��ҵ鸸�� ���, ���� �� �ִ� ���� �� �����ϴ� �κ� ����
  - dp_decrease[i] : i��° ��Ҹ� �� ó���� �����ϸ鼭, i���� (n-1)��° ��ҵ鸸�� ���, ���� �� �ִ� ���� �� �����ϴ� �κ� ����
  - dp_bitonic[i] : i��° ��Ҹ� �������� ���� �� �ִ� ���� �� ������� �κ� ������ ����
  - dp_bitonic[i] = dp_increase[i] + dp_decrease[i] - 1
- dp_bitonic�� ����� �� �� ���� ū ���� ����Ѵ�.
*/
#include <iostream>
using namespace std;

int Max(int x, int y) { return x > y ? x : y; }

int main()
{
    // ������ ���� n
    int n = 0;
    // ������ ��� value
    int value[1000];
    // ���� �� �����ϴ� �κ� ���� dp_increase
    int dp_increase[1000];
    // ���� �� �����ϴ� �κ� ���� dp_decrease
    int dp_decrease[1000];
    // ���� �� ������� �κ� ���� dp_bitonic
    int dp_bitonic[1000];
    // dp_bitonic�� ����� ��� �� ���� ū �� res
    int res = 0;

    // ������ ���� n�� ������ ��� value �Է�
    cin >> n;
    for (int index = 0; index < n; index++)
        cin >> value[index];

    // dp_increase, dp_decrease, dp_bitonic�� ��� 1�� �ʱ�ȭ
    for (int index = 0; index < n; index++)
    {
        dp_increase[index] = 1;
        dp_decrease[index] = 1;
        dp_bitonic[index] = 1;
    }

    // 0��° ��Һ��� (n-1)��° ��ұ��� ������� ���� �� �����ϴ� �κ� ���� ���ϱ�
    for (int currentIndex = 0; currentIndex < n; currentIndex++)
        for (int prevIndex = 0; prevIndex < currentIndex; prevIndex++)
            if (value[currentIndex] > value[prevIndex])
                dp_increase[currentIndex] = Max(dp_increase[currentIndex], dp_increase[prevIndex] + 1);

    // (n-1)��° ��Һ��� 0��° ��ұ��� ������� ���� �� �����ϴ� �κ� ���� ���ϱ�
    for (int currentIndex = n - 1; currentIndex > -1; currentIndex--)
        for (int prevIndex = n - 1; prevIndex > currentIndex; prevIndex--)
            if (value[currentIndex] > value[prevIndex])
                dp_decrease[currentIndex] = Max(dp_decrease[currentIndex], dp_decrease[prevIndex] + 1);

    // 0��° ��Һ��� (n-1)��° ��ұ��� ���� �� bitonic �κ� ���� ���
    for (int index = 0; index < n; index++)
    {
        dp_bitonic[index] = dp_increase[index] + dp_decrease[index] - 1;

        if (res < dp_bitonic[index])
            res = dp_bitonic[index];
    }

    // ��� ���
    cout << res;

    return 0;
}

/*
�� ���� Ǯ�� ���� ����
- ������ �������� �ʰ� �ذ��Ϸ��� ��
  -> ������ '���� �� �����ϴ� �κ� ������ ���� + ���� �� �����ϴ� �κ� ������ ����'�� ����
- ������ Ǭ �������� ���ļ� �����ϴ� ����
  -> ������ ����� ������ Ǯ��ô��� �����غ���
*/