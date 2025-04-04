#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {0, };
    int x, y, div;
    
    for(int i=0; i<6; ++i)
        cin >> arr[i];
    
    div = arr[0] * arr[4] - arr[1] * arr[3];
    x = (arr[2] * arr[4] - arr[1] * arr[5]) / div;
    y = (arr[0] * arr[5] - arr[2] * arr[3]) / div;
    
    cout << x << ' ' << y;
    
    return 0;
}
