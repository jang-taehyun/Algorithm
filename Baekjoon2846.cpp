#include <iostream>
using namespace std;

int main()
{
    int len;
    int arr[1000] = {0, };
    int tmp=0, res=0;
    
    cin >> len;
    for(int i=0; i<len; i++)
        cin >> arr[i];
    
    for(int i=1; i<len; i++)
    {
        if(arr[i-1] < arr[i])
            tmp += (arr[i] - arr[i-1]);
        else
        {
            if(tmp > res)
                res = tmp;
            tmp = 0;
        }
    }
    
    if(tmp > res)
        res = tmp;
    
    cout << res;
    
    return 0;
}
