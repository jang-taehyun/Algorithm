#include <iostream>
using namespace std;

unsigned int dp[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int arraylen, inputlen;
    int input1, input2;
    unsigned int res;
    
    cin >> arraylen >> inputlen;
    
    cin >> input1;
    dp[0] = input1;
    for(int j=1; j<arraylen; j++)
    {
        cin >> input1;
        dp[j] = dp[j-1] + input1;
    }
    
    while(inputlen--)
    {
        cin >> input1 >> input2;
        
        input2 -= 1;
        input1 -= 2;
        
        res = dp[input2];
        if(input1 >= 0)
            res -= dp[input1];
        
        cout << res << '\n';
    }
    
    return 0;
}
