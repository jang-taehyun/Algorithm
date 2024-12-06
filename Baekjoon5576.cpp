#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr1[10];
    int arr2[10];
    int res1=0, res2=0;
    
    for(int i=0; i<10; i++)
        cin >> arr1[i];
    for(int i=0; i<10; i++)
        cin >> arr2[i];
    
    sort(arr1, arr1+10);
    sort(arr2, arr2+10);
    
    for(int i=9; i>6; i--)
        res1 += arr1[i];
    for(int i=9; i>6; i--)
        res2 += arr2[i];
    
    cout << res1 << ' ' << res2;
    
    return 0;
}
