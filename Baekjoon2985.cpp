#include <iostream>
using namespace std;

int main()
{
    int arr[3];
    bool IsFind = false;
    
    for(int i=0; i<3; i++)
        cin >> arr[i];
    
    for(int i=0; i<4; i++)
    {
        if(IsFind)
            break;
        
        switch(i)
        {
            case 0:
                {
                    if(arr[0] == arr[1] + arr[2])
                    {
                        cout << arr[0] << '=' << arr[1] << '+' << arr[2];
                        IsFind = true;
                    }
                    else if(arr[0] + arr[1] == arr[2])
                    {
                        cout << arr[0] << '+' << arr[1] << '=' << arr[2];
                        IsFind = true;
                    }
                }
                break;
            case 1:
                {
                    if(arr[0] == arr[1] - arr[2])
                    {
                        cout << arr[0] << '=' << arr[1] << '-' << arr[2];
                        IsFind = true;
                    }
                    else if(arr[0] - arr[1] == arr[2])
                    {
                        cout << arr[0] << '-' << arr[1] << '=' << arr[2];
                        IsFind = true;
                    }
                }
                break;
            case 2:
                {
                    if(arr[0] == arr[1] * arr[2])
                    {
                        cout << arr[0] << '=' << arr[1] << '*' << arr[2];
                        IsFind = true;
                    }
                    else if(arr[0] * arr[1] == arr[2])
                    {
                        cout << arr[0] << '*' << arr[1] << '=' << arr[2];
                        IsFind = true;
                    }
                }
                break;
            case 3:
                {
                    if(arr[0] == arr[1] / arr[2])
                    {
                        cout << arr[0] << '=' << arr[1] << '/' << arr[2];
                        IsFind = true;
                    }
                    else if(arr[0] / arr[1] == arr[2])
                    {
                        cout << arr[0] << '/' << arr[1] << '=' << arr[2];
                        IsFind = true;
                    }
                }
                break;
        }
    }
    
    return 0;
}
