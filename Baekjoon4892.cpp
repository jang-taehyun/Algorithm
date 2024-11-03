#include <iostream>
using namespace std;

typedef unsigned int UINT;

int main()
{
    UINT arr[4];
    UINT seq = 1;
    
    while(1)
    {
        cin >> arr[0];
        if(!arr[0])
            break;
        
        arr[1] = 3 * arr[0];
        
        cout << seq << ". ";
        if(arr[1] % 2)
        {
            cout << "odd ";
            arr[2] = (arr[1] + 1) / 2;
        }
        else
        {
            cout << "even ";
            arr[2] = arr[1] / 2;
        }
        
        arr[3] = 3 * arr[2];
        cout << arr[3] / 9 << '\n';
        
        seq++;
    }
    
    return 0;
}
