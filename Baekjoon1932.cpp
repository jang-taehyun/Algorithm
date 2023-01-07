/*
problem : ũ�Ⱑ n�� ���� �ﰢ���� ���� ��, �� �������� �����Ͽ� �������� ���õ� ���� ���� �ִ밡 �Ǵ� ��θ� ���϶�.
input : ���� �ﰢ���� ũ�� n, �ﰢ���� �̷�� �ִ� ���� i(1 <= n <= 500, 0 <= i <= 9999)
output : �� �������� �� �Ʒ����� ���� ��� �� ���õ� ���� ���� �ִ밪

idea
- ũ�Ⱑ 5�� ���� �ﰢ���� �Ʒ��� ���� �־����ٰ� ����. ���⼭ (i, j)�� i��° column���� �����ϴ� ������ �� j��° ������ �ǹ��Ѵ�.
      7
     3 8
    8 1 0
   2 7 4 4
  4 5 2 6 5
- ���⿡�� 3��° column���� ������ ���� ��찡 �߻��Ѵ�.
  1) (3, 1) : (2, 1)���� ����� �ִ밪 + (3, 1)
  2) (3, 2) : max{(2, 1)���� ����� �ִ밪, (2, 2)���� ����� �ִ밪} + (3, 2)
  3) (3, 3) : (2, 2)���� ����� �ִ밪 + (2, 2)
- ��, i��° column������ ������ ���� ��찡 �߻��Ѵ�.
  1) j�� 1�� ��� : (i-1, 1)���� ����� �ִ밪 + (i, j)
  2) j�� i�� ���� ��� : (i-1, j-1)���� ����� �ִ밪 + (i, j)
  3) �׿� : max{(i-1, j-1)���� ����� �ִ밪, (i-1, j)���� ����� �ִ밪} + (i, j)
- �̸� �̿��� ����� ����
  dp[i][j] : ���� ���(i, j)���� ���� �� ���� �� �ִ� �ִ밪
  j == 1 : dp[i-1][j] + value[i][j];
  j == i : dp[i-1][j-1] + value[i][j];
  �� ��   : max(dp[i-1][j-1], dp[i-1][j]) + value[i][j]
- ������� 2���� n���� �ݺ����� ���鼭 ����ϰ�, �ݺ����� ������ n��° column���� �����ϴ� �� �� �ִ밪�� ã�´�.
*/

#include <iostream>
#include <cstring>
using namespace std;

int Max(int x, int y) { return x > y ? x : y; }

int main()
{
    // ���� �ﰢ���� ũ�� n
    int n = 0;
    // ���� �ﰢ���� ���� ���� 2���� �迭 value
    int value[500][500];
    // ������� �̿��� ���� ��α��� ���� �� �ִ� �ִ밪 2���� �迭 dp
    int dp[500][500];
    // �ִ밪 res
    int res = 0;

    // value�� dp �ʱ�ȭ
    memset(value, 0, sizeof(value));
    memset(dp, 0, sizeof(dp));

    // ���� �ﰢ���� ũ�� n�� �ﰢ���� ���� ���� �Է�
    cin >> n;
    for (int column = 0; column < n; column++)
        for (int row = 0; row < column + 1; row++)
            cin >> value[column][row];

    // ���� �ﰢ���� �� �������� dp �ʱ�ȭ
    dp[0][0] = value[0][0];

    // 1��° column���� ������ n��° column���� ������� �̿��� ���� ��α��� ����� �ִ밪 ���
    for (int column = 1; column < n; column++)
        for (int row = 0; row < column + 1; row++)
        {
            if (row == 0)
                dp[column][row] = dp[column - 1][row];
            else if (row == column)
                dp[column][row] = dp[column - 1][row - 1];
            else
                dp[column][row] = max(dp[column - 1][row - 1], dp[column - 1][row]);

            dp[column][row] += value[column][row];
        }

    // dp���� n��° column�� ����� �� �� �ִ밪�� ã�� ���
    for (int i = 0; i < n; i++)
        if (res < dp[n - 1][i])
            res = dp[n - 1][i];
    cout << res;

    return 0;
}