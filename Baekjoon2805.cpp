#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ULL;

int main()
{
    vector<ULL> v;
    ULL len, target;
    ULL s=0, e, mid, input;
    ULL cnt=0;
    ULL res=0;
    
    cin >> len >> target;
    for(int i=0; i<len; ++i)
    {
        cin >> input;
        v.push_back(input);
        
        if(input > e)
            e = input;
    }
    
    while(s <= e)
    {
        mid = (s+e) / 2;
        
        cnt = 0;
        for(int i=0; i<len; ++i)
            if(v[i] > mid)
                cnt += (v[i] - mid);
        
        if(target <= cnt)
        {
            if(res < mid)
                res = mid;
            
            s = mid+1;
        }
        else
            e = mid-1;
    }
    
    cout << res;
    
    return 0;
}
