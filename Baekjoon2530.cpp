#include <iostream>
using namespace std;

int main()
{
    int arr[3];
    int adder=0;
    int tmp;
    
    for(int i=0; i<3; i++)
        cin >> arr[i];
    cin >> adder;
    
    for(int i=2; i>=0; i--)
    {
        arr[i] += adder;
        
        adder = 0;
        tmp = (i ? 60 : 24);
        
        if(arr[i] >= tmp)
        {
            adder = arr[i] / tmp;
            arr[i] %= tmp;
        }
    }
    
    for(int i=0; i<3; i++)
        cout << arr[i] << ' ';
    
    return 0;
}
