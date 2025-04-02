#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len;
    int arr[100000] = {0, };
    int test;
    int dp[100000] = {0, };
    int idx1, idx2;
    
    cin >> len;
    for(int i=0; i<len; ++i)
    {
        cin >> arr[i];
        
        if(i)
            dp[i] = dp[i-1] + arr[i];
        else
            dp[i] = arr[i];
    }
    
    cin >> test;
    while(test--)
    {
        cin >> idx1 >> idx2;
        --idx1;
        --idx2;
        
        cout << (dp[idx2] - dp[idx1] + arr[idx1]) << '\n';
    }
    
    return 0;
}
