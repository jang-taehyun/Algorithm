#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[3] = {0, };
    int res;
    
    for(int i=0; i<3; i++)
        cin >> arr[i];
    
    sort(arr, arr+3);
    
    if((double)(arr[1] - arr[0]) == ((double)(arr[2] - arr[1]) / 2.f))
    {
        res = (arr[1] - arr[0]) + arr[1];
    }
    else if((double)(arr[2] - arr[1]) == ((double)(arr[1] - arr[0]) / 2.f))
    {
        res = (arr[2] - arr[1]) + arr[0];
    }
    else
    {
        res = arr[2] + (arr[1] - arr[0]);
    }
    
    cout << res;
    
    return 0;
    }