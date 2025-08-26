#include <iostream>
using namespace std;

int arr[100001] = {0, };

int main()
{
    int cnt, len, tmp;
    int res;
    
    cin >> cnt >> len;
    for(int i=1; i<=cnt; ++i)
    {
        cin >> tmp;
        arr[i] = arr[i-1] + tmp;
    }
    
    res = arr[len];
    for(int i=len; i<=cnt; ++i)
    {
        tmp = arr[i] - arr[i-len];
        
        if(res < tmp)
            res = tmp;
    }
    
    cout << res;
    
    return 0;
}
