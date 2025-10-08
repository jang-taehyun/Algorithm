#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input1, input2;
    vector<vector<int>> dp;
    stack<char> str;
    int idx1, idx2;
    
    cin >> input1 >> input2;
    
    dp.resize(input2.length());
    for(int i=0; i<dp.size(); ++i)
        dp[i].resize(input1.length(), 0);
    
    if(input1[0] == input2[0])
        dp[0][0] = 1;
    
    for(int i=1; i<input1.length(); ++i)
        dp[0][i] = (input1[i] == input2[0] ? 1 : dp[0][i-1]);
    for(int i=1; i<input2.length(); ++i)
        dp[i][0] = (input1[0] == input2[i] ? 1 : dp[i-1][0]);
    
    for(int i=1; i<input2.length(); ++i)
        for(int j=1; j<input1.length(); ++j)
        {
            if(input1[j] == input2[i])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = (dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);
        }
    
    cout << dp[input2.length()-1][input1.length()-1];
    
    if(dp[input2.length()-1][input1.length()-1])
    {
        idx1 = input2.length()-1;
        idx2 = input1.length()-1;
        
        while(idx1 >= 0 && idx2 >= 0)
        {
            if(input1[idx2] == input2[idx1])
            {
                str.push(input1[idx2]);
                --idx1;
                --idx2;
            }
            else
            {
                if(idx1-1 >= 0 && idx2-1 >= 0)
                {
                    if(dp[idx1-1][idx2] > dp[idx1][idx2-1])
                        --idx1;
                    else
                        --idx2;
                }
                else if(idx1-1 >= 0)
                    --idx1;
                else if(idx2-1 >= 0)
                    --idx2;
                else
                {
                    --idx1;
                    --idx2;
                }
                    
            }
        }
        
        cout << '\n';
        while(!str.empty())
        {
            cout << str.top();
            str.pop();
        }
    }
    
    return 0;
}
