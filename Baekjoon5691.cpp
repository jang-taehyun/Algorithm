#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[2] = { 0, };
    int tmp1, tmp2, res;
    
    while(1)
    {
        for(int i=0; i<2; i++)
            cin >> arr[i];
        
        if(!arr[0] && !arr[1])
            break;
        
        sort(arr, arr+2);
        
        tmp1 = arr[0] * 2 - arr[1];
        tmp2 = arr[1] * 2 - arr[0];
        
        res = (tmp1 < tmp2 ? tmp1 : tmp2);
        
        if(!((arr[0] + arr[1]) % 2))
            res = (res < ((arr[0] + arr[1]) / 2) ? res : ((arr[0] + arr[1]) / 2));
        
        cout << res << '\n';
    }
    
    return 0;
}
