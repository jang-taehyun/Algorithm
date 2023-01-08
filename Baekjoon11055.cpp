/*
problem : ���� A����, �� ������ ���� �κ� ���� �� ���� ���� ū ���� ���ض�
input : ���� A�� ũ�� n, ���� A�� ��� value(1 <= n <= 1000, 1 <= value <= 1000)
output : ���� �κ� ������ �� �� ���� ū ��

idea
- ���� A��, {1, 100, 2, 50}�� �־����ٰ� �����ϰ�, �� ��Ҹ� �����ϴ� ���� �κ� ������ ������ ����.
  1��° ��Ҹ� �����ϴ� ���� �κ� ���� : 1
  2��° ��Ҹ� �����ϴ� ���� �κ� ���� : 1, 100
  3��° ��Ҹ� �����ϴ� ���� �κ� ���� : 1, 2
  4��° ��Ҹ� �����ϴ� ���� �κ� ���� : 1, 2, 50
- ���⿡�� '�� ��Ҹ� �����ϴ� �κ� ���� �� ���� ���� ����'�� ������ ����.
  1��° ��Ҹ� �����ϴ� ���� �κ� ���� : 1
  2��° ��Ҹ� �����ϴ� ���� �κ� ���� : 100
  3��° ��Ҹ� �����ϴ� ���� �κ� ���� : 2
  4��° ��Ҹ� �����ϴ� ���� �κ� ���� : 50
- ���� dp[i]�� 'i��° ��Ҹ� �����ϴ� ���� �κ� ������ �� �� �ִ밪'�̶�� ����.
  �׷��ٸ�, dp[i]�� �ʱⰪ�� '�� ��Ҹ� �����ϴ� �κ� ���� �� ���� ���� ����'�̴�.
- dp[i]�� 1���� (i-1)��°���� ��� �� i��° ��Һ��� �����鼭(�̸� j��� ����.),
  (dp[j] + value[i])�� dp[i]���� Ŀ�� �Ѵ�.
- ����� ����
  - dp[i] = max(dp[i], dp[j] + value[i]);
- ������ ������ Ž���� ��, dp�� ����� �� �� �ִ밪�� ã�� ���
*/

#include <iostream>
#include <cstring>
using namespace std;

int Max(int x, int y) { return x > y ? x : y; }

int main()
{
    // ������ ���� n
    int n = 0;
    // ������ ��� value
    int value[1000];
    // ������� �̿��� �ִ밪�� ������ dp
    int dp[1000];
    // ������� ����� �� �� �ִ밪�� ������ max
    int max = 0;

    // value�� dp �ʱ�ȭ
    memset(value, 0, sizeof(value));
    memset(dp, 0, sizeof(dp));

    // ������ ���� n�� ������ ��� value �Է� & dp �ʱ�ȭ
    cin >> n;
    for (int index = 0; index < n; index++)
    {
        cin >> value[index];
        dp[index] = value[index];
    }

    // 0���� (n-1)���� ������� �̿��� �ִ밪 ���
    for (int currentIndex = 0; currentIndex < n; currentIndex++)
        for (int prevIndex = 0; prevIndex < currentIndex; prevIndex++)
            if (value[currentIndex] > value[prevIndex])
                dp[currentIndex] = Max(dp[currentIndex], dp[prevIndex] + value[currentIndex]);

    // �ִ밪�� ã�� ��� ���
    for (int index = 0; index < n; index++)
        max = Max(max, dp[index]);
    cout << max;


    return 0;
}

/*
�� ���� Ǯ�� ���� ����
- �ٷ� ������ ���� ������ �̿�
- ���ø� ���� Ǭ ��, ������� ���� & ������� �����ϰ� ������
  -> dp�� �ǹ̸� ���� ���� ��, ������� �����ϴ� ����� �ִ�.
  -> ��츦 ������ ������, ����ؾ� �� ���귮�� �������� ���ǵ� ������
*/