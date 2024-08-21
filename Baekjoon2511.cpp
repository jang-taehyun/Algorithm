#include <iostream>
using namespace std;

int main()
{
    int arr[2][10];
    int a=0, b=0;
    char winner[10];
    char tmp = 'D';
    
    for(int i=0; i<2; i++)
        for(int j=0; j<10; j++)
            cin >> arr[i][j];
    
    for(int i=0; i<10; i++)
    {
        if(arr[0][i] > arr[1][i])
        {
            a += 3;
            winner[i] = 'A';
        }
        else if(arr[0][i] < arr[1][i])
        {
            b += 3;
            winner[i] = 'B';
        }
        else
        {
            a += 1;
            b += 1;
            winner[i] = 'D';
        }
    }
    
    cout << a << ' ' << b << '\n';
    if(a > b)
        cout << 'A';
    else if(a < b)
        cout << 'B';
    else
    {
        for(int i=9; i>=0; i--)
            if(winner[i] != 'D')
            {
                tmp = winner[i];
                break;
            }  
        
        cout << tmp;
    }
        
    
    return 0;
}
