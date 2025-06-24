#include <iostream>
#include <cstring>
using namespace std;

char input1[1001] = {0, };
char input2[1001] = {0, };
int dp[1000][1000] = {0, };
int adder = 0;
int res = 0;

inline int MAXNUM(int n1, int n2)
{
    return (n1 > n2 ? n1 : n2);
}

int main()
{
    cin >> input1 >> input2;
    
    dp[0][0] = (input1[0] == input2[0] ? 1 : 0);
    for(int i=1; i<strlen(input2); ++i)
    {
        adder = (input1[0] == input2[i] ? 1 : 0);
        dp[0][i] = MAXNUM(dp[0][i-1], adder);
    }
    for(int i=1; i<strlen(input1); ++i)
    {
        adder = (input1[i] == input2[0] ? 1 : 0);
        dp[i][0] = MAXNUM(dp[i-1][0], adder);
    }
    
    for(int i=1; i<strlen(input1); ++i)
    {
        for(int j=1; j<strlen(input2); ++j)
        {
            if(input1[i] == input2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = MAXNUM(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    cout << dp[strlen(input1)-1][strlen(input2)-1];
    
    return 0;
}
