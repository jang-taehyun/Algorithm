#include <iostream>
#define MIN(x, y) (x) < (y) ? (x) : (y)
using namespace std;

int dp[1000001];
int seq[1000001];
int target;

int main()
{
    cin >> target;
    
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    
    seq[1] = 0;
    seq[2] = 1;
    seq[3] = 1;
    
    for(int i=4; i<=target; i++)
    {
        dp[i] = dp[i-1];
        seq[i] = i-1;
        
        if(!(i%3) && dp[i] > dp[i/3])
        {
            dp[i] = dp[i/3];
            seq[i] = i/3;
        }
        if(!(i%2) && dp[i] > dp[i/2])
        {
            dp[i] = dp[i/2];
            seq[i] = i/2;
        }
        
        dp[i]++;
    }
    
    cout << dp[target] << '\n';
    cout << target << ' ';
    while(seq[target])
    {
        cout << seq[target] << ' ';
        target = seq[target];
    }
    
    return 0;
}
