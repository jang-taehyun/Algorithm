#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len, bound;
    vector<int> arr, cnt;
    int left=0, right=0, res=1;
    
    cin >> len >> bound;
    
    arr.resize(len, 0);
    for(int i=0; i<len; ++i)
    {
        cin >> arr[i];
        
        if(res < arr[i])
            res = arr[i];
    }
    cnt.resize(res+1, 0);
    
    res = 1;
    while(left < len && right < len)
    {
        while(right < len)
        {
            ++cnt[arr[right]];
            
            if(cnt[arr[right]] > bound)
                break;
            
            ++right;
        }
        
        res = (right - left > res ? right - left : res);
        
        if(right < len)
        {
            while(left < right && cnt[arr[right]] > bound)
            {
                --cnt[arr[left]];
                ++left;
            }
        }
        
        ++right;
    }
    
    cout << res;
    
    return 0;
}
