#include <iostream>
#include <vector>
using namespace std;

inline int MINNUM(int n1, int n2)
{
    return (n1 < n2 ? n1 : n2);
}

int main()
{
    int len;
    vector<int> v;
    int tmp;
    int target;
    bool IsExist[10001] = {false, };
    int idx;
    int dp[10001] = {0, };
    
    cin >> len >> target;
    while(len--)
    {
        cin >> tmp;
        if(IsExist[tmp])
            continue;
        if(tmp > target)
            continue;
        
        v.push_back(tmp);
        IsExist[tmp] = true;
        dp[tmp] = 1;
    }
    
    for(int i=1; i<=target; ++i)
    {
        if(1 == dp[i])
            continue;
        
        dp[i] = -1;
        
        for(int j=0; j<v.size(); ++j)
        {
            idx = i - v[j];
            
            if(idx <= 0)
                continue;
            if(dp[idx] <= 0)
                continue;
            
            if(-1 == dp[i])
                dp[i] = dp[v[j]] + dp[idx];
            else
                dp[i] = MINNUM(dp[i], dp[v[j]] + dp[idx]);
        }
    }
    
    cout << dp[target];
    
    return 0;
}
