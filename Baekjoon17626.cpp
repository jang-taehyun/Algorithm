#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    int n;
    vector<int> dp;
    int pivot = 1, tmp;
    
    cin >> n;
    dp.resize(n+1, INT_MAX);
    
    dp[1] = 1;
    for(int i=2; i<=n; ++i)
    {
        if((pivot + 1) * (pivot + 1) == i)
        {
            pivot++;
            dp[i] = 1;
        }
        else
        {
            for(int j=1; j<=pivot; ++j)
            {
                tmp = dp[j*j] + dp[i-(j*j)];
                if(dp[i] > tmp)
                    dp[i] = tmp;
            }
        }
            
    }
    
    cout << dp[n];
    
    return 0;
}
