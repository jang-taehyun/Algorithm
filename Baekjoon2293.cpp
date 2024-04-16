/*
problem : n가지 동전을 이용해 숫자 k를 만들 수 있는 경우의 수를 구해라.
input : 동전의 가치들 m, 만들고자 하는 숫자 k
output : n가지 동전을 이용해 숫자 k를 만들 수 있는 경우의 수

idea
- 'dp[i] = k'는 i번째 숫자를 만들 수 있는 가지 수는 k라는 의미
- dp[i] = dp[i] + dp[i - coin[j]] (coin[j]는 i보다는 작다)

참고 자료 : https://yabmoons.tistory.com/491
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

    // 동전의 종류 및 만들고자 하는 숫자 입력
    cin >> CoinCount >> target;
    for (int i = 0; i < CoinCount; i++)
        cin >> coin[i];

    // 동전의 가치들을 오름차순으로 정렬
    sort(coin, coin + CoinCount);

    // i를 0부터 CoinCount-1까지 반복하면서 dp 계산
    for (int i = 0; i < CoinCount; i++)
        for (int j = coin[i]; j <= target; j++)
            dp[j] += dp[j - coin[i]];

    // 결과값 출력
    cout << dp[target];

    return 0;
}