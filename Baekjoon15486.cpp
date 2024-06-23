#include <iostream>
using namespace std;

int period;
int work[1500000];
int price[1500000];
int dp[1500001];

int main()
{
    int deadline;
    int res=0;
    
    cin >> period;
    for(int i=0; i<period; i++)
        cin >> work[i] >> price[i];
    
    for(int i=period-1; i>=0; i--)
    {
        deadline = i + work[i];
        
        if(deadline > period)
            dp[i] = dp[i+1];
        else
            dp[i] = max(dp[i+1], dp[deadline] + price[i]);
        
        res = max(res, dp[i]);
    }
    
    cout << res;
    
    return 0;
}
