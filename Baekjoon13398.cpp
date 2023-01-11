/*
problem : ���� S���� ���ӵ� �� ���� ���ڸ� ������ ���� �� �ִ� �ִ� ���� ���ض�
input : ������ ���� n, ������ ��� value
output : ���ӵ� �� ���� ���ڸ� ������ ���� �� �ִ� �ִ� ��

idea
- dp[i][k]�� 'i��° ��ҿ��� k ��츦 �������� �� ���� �� �ִ� ���� ���� �ִ�'�̶�� ����.
  k=0 �̸� Ư�� ��Ҹ� �������� �ʾ��� �� ���� �� �ִ� ���� ���� �ִ�, k=1 �̸� Ư�� ��Ҹ� ������ �� ���� �� �ִ� ���� ���� �ִ��̴�.
- ������� ������ ����.
  dp[i][0] = max(dp[i-1][0]+value[i], value[i]);
  dp[i][1] = max(dp[i-1][0], dp[i-1][1]+value[i]);
- ���⿡�� Ư�� ��Ҹ� ������ �� ���� �� �ִ� ���� ���� �ִ밪�� ������ ���� ��� �� ū ���� �����Ѵ�.
  1) i��° ��Ҹ� ������ ��� : dp[i-1][0]
  2) i��° ������ ��Ҹ� ������ ��� : dp[i-1][1] + value[i]
- dp�� �����ϴ� �� �� ���� ū ���� ã�Ƽ� ���

*/
#include <iostream>
using namespace std;

int Max(int x, int y) { return x > y ? x : y; }

int main()
{
    // ������ ���� n
    int n = 0;
    // ������ ��� value
    int value[100000];
    // ������� ���� ���� ���� ���� �ִ밪 dp
    int dp[100000][2];
    // dp�� ����� �� �� ���� ū �� res
    int res = 0;

    // ������ ���� n�� ������ ��� value �Է� & ������ ��� �� ���� ���� ���� min�� ����
    cin >> n;
    for (int index = 0; index < n; index++)
        cin >> value[index];

    // ������� �̿��� �� ��Ҹ� Ž���� �� ������ ��쿡�� �ִ밪 ����
    dp[0][0] = value[0];
    dp[0][1] = value[0];
    for (int index = 1; index < n; index++)
    {
        dp[index][0] = Max(dp[index - 1][0] + value[index], value[index]);
        dp[index][1] = Max(dp[index - 1][0], dp[index - 1][1] + value[index]);
    }

    // dp�� ����� �� �� ���� ū ���� ã�Ƽ� ���
    res = dp[0][0];
    for (int column = 0; column < n; column++)
        for (int row = 0; row < 2; row++)
            if (dp[column][row] > res)
                res = dp[column][row];
    cout << res;

    return 0;
}