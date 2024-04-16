/*
problem : n���� ������ �̿��� ���� k�� ���� �� �ִ� ����� ���� ���ض�.
input : ������ ��ġ�� m, ������� �ϴ� ���� k
output : n���� ������ �̿��� ���� k�� ���� �� �ִ� ����� ��

idea
- 'dp[i] = k'�� i��° ���ڸ� ���� �� �ִ� ���� ���� k��� �ǹ�
- dp[i] = dp[i] + dp[i - coin[j]] (coin[j]�� i���ٴ� �۴�)

���� �ڷ� : https://yabmoons.tistory.com/491
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int coin[100];
int CoinCount, target;
int dp[10001];

int main()
{
    memset(coin, 0, sizeof(coin));
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    // ������ ���� �� ������� �ϴ� ���� �Է�
    cin >> CoinCount >> target;
    for (int i = 0; i < CoinCount; i++)
        cin >> coin[i];

    // ������ ��ġ���� ������������ ����
    sort(coin, coin + CoinCount);

    // i�� 0���� CoinCount-1���� �ݺ��ϸ鼭 dp ���
    for (int i = 0; i < CoinCount; i++)
        for (int j = coin[i]; j <= target; j++)
            dp[j] += dp[j - coin[i]];

    // ����� ���
    cout << dp[target];

    return 0;
}