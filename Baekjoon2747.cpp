#include <iostream>
using namespace std;

int main()
{
    int len;
    int arr[46];

    cin >> len;
    
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<=len; i++)
        arr[i] = arr[i-1] + arr[i-2];
    
    cout << arr[len];
    
    return 0;
}
