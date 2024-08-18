#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int len, choose;
    int res, tmp;
    
    cin >> len >> choose;
    for(int i=0; i<len; i++)
        cin >> arr[i];
    
    for(int i=0; i+choose-1<len; i++)
    {
        tmp = 0;
        for(int j=i; j<i+choose; j++)
            tmp += arr[j];
        
        if(!i || tmp > res)
            res = tmp;
    }
    
    cout << res;
    
    return 0;
}
