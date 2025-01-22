#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int arr[10] = {0, };
    int tmp;
    int res = 9999;
    int resIdx = 0;
    
    for(int i=0; i<10; i++)
    {
        cin >> tmp;
        
        if(!i)
            arr[i] = tmp;
        else
            arr[i] = tmp + arr[i-1];
    }
    
    for(int i=0; i<10; i++)
    {
        tmp = abs(100 - arr[i]);
        
        if(res >= tmp)
        {
            res = tmp;
            resIdx = i;
        }
    }
    
    cout << arr[resIdx];
    
    return 0;
}
