#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int test;
    int coinLen, input, target;
    int dp[10001] = {0, };
    vector<int> coin;
    
    cin >> test;
    while(test--)
    {
        memset(dp, 0, sizeof(dp));
        coin.clear();
        dp[0] = 1;
        
        cin >> coinLen;
        while(coinLen--)
        {
            cin >> input;
            coin.push_back(input);
        }
        
        cin >> target;
        
        for(int i=0; i<coin.size(); ++i)
        {
            for(int j=coin[i]; j<=target; ++j)
                dp[j] += (dp[j-coin[i]]);
        }
        
        cout << dp[target] << '\n';
    }
    
    return 0;
}
