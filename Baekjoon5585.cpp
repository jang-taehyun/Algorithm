#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {500, 100, 50, 10, 5, 1};
    int input;
    int res = 0;
    
    cin >> input;
    
    input = 1000 - input;
    for(int i=0; i<6; i++)
    {
        res += (input / arr[i]);
        input %= arr[i];
    }
    
    cout << res;
    
    return 0;
}
