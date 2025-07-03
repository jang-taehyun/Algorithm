#include <iostream>
using namespace std;

int main()
{
    int cnt;
    int arr[3] = {0, };
    
    cin >> cnt;
    while(cnt--)
    {
        for(int i=0; i<3; ++i)
            cin >> arr[i];
        
        if(arr[0] < (arr[1] - arr[2]))
           cout << "advertise" << '\n';
        else if(arr[0] > (arr[1] - arr[2]))
            cout << "do not advertise" << '\n';
        else
            cout << "does not matter" << '\n';
    }
    
    return 0;
}
