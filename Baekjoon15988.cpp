/*
problem : ���� n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ���ض�
input : ���� n (1 <= n <= 1,000,000)
output : 1, 2, 3�� ������ ��Ÿ���� ����� ���� 1,000,000,009���� ���� ������ ���

idea
- ���� n�� 1, 2, 3�� ������ ��Ÿ���� ����� �� = k(n)
1) n=1�� ��, 1�� 1, 2, 3�� ������ ��Ÿ���� ���
   -> 1
   -> k(1) = 1
2) n=2�� ��, 2�� 1, 2, 3�� ������ ��Ÿ���� ���
   -> n=1���� �����ʿ� (+1)�� �ϴ� ��� : 1+1
   -> 2
   -> k(2) = 2
3) n=3�� ��, 3�� 1, 2, 3�� ������ ��Ÿ���� ���
   -> n=1���� �����ʿ� (+2)�� �ϴ� ��� : 1+2
   -> n=2���� �����ʿ� (+1)�� �ϴ� ��� : 1+1+1, 2+1
   -> 3
   -> k(3) = 4
4) n=4�� ��, 4�� 1, 2, 3�� ������ ��Ÿ���� ���
   -> n=1���� �����ʿ� (+3)�� �ϴ� ��� : 1+3
   -> n=2���� �����ʿ� (+2)�� �ϴ� ��� : 1+1+2, 2+2
   -> n=3���� �����ʿ� (+1)�� �ϴ� ��� : 1+2+1, 1+1+1+1, 2+1+1, 3+1
   -> k(4) = 7
5) �̸� �̿��� ����� ����
   - ���� n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� k(n)�̶�� �� ��,
     k(n) = k(n-1) + k(n-2) + k(n-3)
6) �׽�Ʈ ���̽��� �����ϹǷ� �ݺ����� ������, ������ ����� k(n)�� ������ �迭�� �ʿ��ϴ�.
   �׸��� k(n)�� ����� ������ 1,000,000,009�� ������.
   �־��� ���, k(n)�� ���� �� int�� ������ �Ѿ�Ƿ� long long�� ����Ѵ�.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // �׽�Ʈ���̽� T
    int T = 0;
    // �׽�Ʈ ���̽����� �Է¹޴� ���� n
    int n = 0;
    // n�� 1, 2, 3�� ������ ��Ÿ���� ����� �� k(n)�� ������ 1���� �迭 dp
    long long dp[1000001];
    // ������� ���� index�� �����ϴ� end
    int end = 0;

    // dp�� ��� 0���� �ʱ�ȭ ��, n�� 1, 2, 3�� �� �ʱ�ȭ
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    // end �ʱ�ȭ
    end = 3;

    // �׽�Ʈ ���̽� �Է�
    cin >> T;

    // �� �׽�Ʈ ���̽����� n�� 1,2,3�� ������ ��Ÿ���� ����� ����
    // 1,000,000,009�� ���� �������� ���
    while (T--)
    {
        // ���� n �Է�
        cin >> n;

        // dp[n]�� ������ �ʾҴٸ�, (end+1)���� n���� ���
        if (!dp[n])
        {
            for (int i = end + 1; i <= n; i++)
                dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;

            // end�� ������Ʈ
            end = n;
        }

        cout << dp[n] << '\n';
    }

    return 0;
}