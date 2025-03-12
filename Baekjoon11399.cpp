#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int len;
    int arr[1000] = {0, };
    int res = 0;
    
    cin >> len;
    for(int i=0; i<len; ++i)
        cin >> arr[i];
    
    sort(arr, arr+len);
    
    res = arr[0];
    for(int i=1; i<len; ++i)
    {
        arr[i] = arr[i-1] + arr[i];
        res += arr[i];
    }
    
    cout << res;
    
    return 0;
}
