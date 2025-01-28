#include <iostream>
#define MAX(x, y) (x) > (y) ? (x) : (y)
using namespace std;

int main()
{
    int arr[3] = {0, };
    int res1, res2;
    
    for(int i=0; i<3; i++)
        cin >> arr[i];
    
    res1 = arr[1] - arr[0] - 1;
    res2 = arr[2] - arr[1] - 1;
    
    cout << (MAX(res1, res2));
    
    return 0;
}
