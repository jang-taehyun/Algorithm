#include <iostream>
using namespace std;

int main()
{
    int arr[4] = {0, };
    
    for(int i=0; i<4; ++i)
        cin >> arr[i];
    
    cout << abs((arr[0]+arr[3]) - (arr[1]+arr[2]));
    
    return 0;
}
