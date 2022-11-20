/*
problem : ī������ ������ 1���� n���� �ְ�, ������ ī���Ѹ��� ���� pi�� �־����� ��, n���� ī�带 ��� �ִ밪
input : �����Ϸ��� ī���� ���� n, ī���Ѹ����� ���� pi
output : n���� ī�带 �����ϱ� ���� �����ϴ� �ִ밪

idea : All pair shortest problem�� ����
1. n=4�̰�, pi�� 1, 5, 6, 7�� �� �ִ��� ���ϴ� ���
   1) i=1�� ��, max=1
      -> p1 = 1
   2) i=2�� ��, max=5
      -> max1 + max1 = 2, p2 = 5 �� max = 5
   3) i=3�� ��, max=6
      -> max1 + max1 + max1 = 3, max2 + max1 = 6, p3 = 6 �� max=6
   4) i=4�� ��, max=7
      -> max1 + max1 + max1 + max1 = 4, max2 + max2 = 10, max3 + max1 = 7, p4 = 7 �� max=10
2. �̸� �̿��� ����� ����
   -> Max[n] = maximum(pn, Max[n-k] + Max[k]) (1 <= k <= n-1)
      -> Max[1] = p1
*/

#include <iostream>
#include <cstring>
using namespace std;

// ū ���� ã�� ��ȯ�ϴ� �Լ�
int Max(int _x, int _y) { return _x > _y ? _x : _y; }

int main()
{
    // �Է¹��� n
    int inputNumber = 0;
    // price�� �Է¹ް�, max�� ������ �迭
    // �Է°��� 1001�� ���� �����Ƿ�, �迭�� ũ�⸦ 1001�� ����
    int DP[1001];

    cin >> inputNumber;
    for (int i = 1; i <= inputNumber; i++)
        cin >> DP[i];

    // n�� 2���� inputNumber����, max���� �����Ѵ�.
    for (int n = 2; n <= inputNumber; n++)
        // k=1���� n-1���� DP�� ����� ���� ���� �� ū ���� DP�� �����Ѵ�.
        for (int k = 1; k <= n / 2; k++)
            DP[n] = Max(DP[n], DP[n - k] + DP[k]);

    // �ִ� ���
    cout << DP[inputNumber];

    return 0;
}