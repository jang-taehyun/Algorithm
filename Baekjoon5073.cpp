#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[3];
    
    while(1)
    {
        for(int i=0; i<3; i++)
            cin >> arr[i];
        
        if(!arr[0])
            break;
        
        sort(arr, arr+3);
        
        if(arr[0] + arr[1] <= arr[2])
        {
            cout << "Invalid" << '\n';
            continue;
        }
        
        if(arr[0] == arr[1] && arr[1] == arr[2])
            cout << "Equilateral" << '\n';
        else if(arr[0] != arr[1] && arr[1] != arr[2] && arr[0] != arr[2])
            cout << "Scalene" << '\n';
        else
            cout << "Isosceles" << '\n';
    }
    
    return 0;
}
