#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[1000] = {0, };
    int n, k;
    
    cin >> n >> k;
    for(int i=0; i<n; ++i)
        cin >> arr[i];
    
    sort(arr, arr+n, greater<int>());
    cout << arr[k-1];
    
    return 0;
}
