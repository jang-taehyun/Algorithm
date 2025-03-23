#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int len, diff;
    int arr[100000] = {0, };
    int start=0, end=0;
    int res = 0x7fffffff;
    int tmp;
    
    cin >> len >> diff;
    for(int i=0; i<len; ++i)
        cin >> arr[i];
    sort(arr, arr+len);
    
    for(start=0; start<len; ++start)
    {        
        while(end < len)
        {
            tmp = arr[end] - arr[start];
            if(tmp >= diff)
                break;
            
            ++end;
        }
        
        if(end >= len)
            break;
        
        res = (tmp < res ? tmp : res);
    }
    
    cout << res;
    
    return 0;
}
