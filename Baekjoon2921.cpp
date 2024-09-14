/*
dp[i] = dp[i-1] + sum(1~i) + i * (i+1)
*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    int dp[1001];
    int sum[1001];
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        sum[i] = sum[i-1] + i;
        dp[i] = dp[i-1] + sum[i] + (i * (i+1));
    }
    
    cout << dp[n];
    
    return 0;
}
