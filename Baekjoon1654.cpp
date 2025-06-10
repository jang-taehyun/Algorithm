#include <iostream>
using namespace std;

int main()
{
    long long len, target;
    long long arr[10000] = {0, };
    long long s=1, e=0;
    long long mid;
    long long cnt=0;
    long long res=0;
    
    cin >> len >> target;
    for(int i=0; i<len; ++i)
    {
        cin >> arr[i];
        
        if(arr[i] > e)
            e = arr[i];
    }
    
    while(s <= e)
    {   
        mid = (s+e) / 2;
        
        cnt = 0;
        for(int i=0; i<len; ++i)
            cnt += (arr[i] / mid);
        
        if(cnt >= target)
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
