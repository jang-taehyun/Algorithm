#include <iostream>
using namespace std;

int main()
{
    int arr[10000] = {0, };
    int all, len, res=0;
    int s=1, e=0, mid, sum=0;
    
    cin >> len;
    for(int i=0; i<len; ++i)
    {
        cin >> arr[i];
        
        if(e < arr[i])
            e = arr[i];
    }
    cin >> all;
    
    while(s <= e)
    {
        mid = (s+e)/2;
        
        sum=0;
        for(int i=0; i<len; ++i)
        {
            if(arr[i] <= mid)
                sum += arr[i];
            else
                sum += mid;
        }
        
        if(sum <= all)
        {
            res = mid;
            s = mid+1;
        }
        else
            e = mid-1;
    }
    
    cout << res;
    
    return 0;
}
