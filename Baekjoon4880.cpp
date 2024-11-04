#include <iostream>
using namespace std;

int main()
{
    int arr[3];
    
    while(1)
    {
        for(int i=0; i<3; i++)
            cin >> arr[i];
        
        if(!arr[0] && !arr[1] && !arr[2])
            break;
        
        if((arr[0] && arr[1] && arr[2]) &&
           !(arr[1] % arr[0]) && !(arr[2] % arr[1]))
        {
            if(arr[1] / arr[0] == arr[2] / arr[1])
                cout << "GP " << (arr[2] * (arr[2] / arr[1])) << '\n';
            else
                cout << "AP " << (arr[2] + (arr[1] - arr[0])) << '\n';
        }
        else
            cout << "AP " << (arr[2] + (arr[1] - arr[0])) << '\n';
    }
    
    return 0;
}
