#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int len, bound;
    vector<int> sum;
    int left=0, right, mid, s, cnt, res=1000000001;
    
    cin >> len >> bound;
    
    sum.resize(len+1, 0);
    for(int i=1; i<=len; ++i)
    {
        cin >> sum[i];
        if(left < sum[i])
            left = sum[i];
        
        sum[i] += sum[i-1];
    }
    
    right = sum[len];
    while(left < right)
    {
        mid = (left + right) / 2;
        
        cnt = 0;
        s = 0;
        for(int i=1; i<=len; ++i)
        {
            if(sum[i] - sum[s] > mid)
            {
                s = i-1;
                ++cnt;
            }
        }
        
        if(cnt + 1 <= bound)
        {
            right = mid;
            res = (mid < res ? mid : res);
        }
        else
            left = mid + 1;
    }
    
    if(res < 1000000001)
        cout << res;
    else
        cout << right;
    
    return 0;
}
