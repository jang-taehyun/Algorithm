#include <iostream>
using namespace std;

int main()
{
    int n, k;
    int dp[11][11] = {0, };
    
    cin >> n >> k;
    
    for(int i=0; i<=n; ++i)
        for(int j=0; j<=min(k, i); ++j)
        {
            if(i == j || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    
    cout << dp[n][k];
    
    return 0;
}
