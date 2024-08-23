#include <iostream>
using namespace std;

int main()
{
    int arr[9][9];
    int col, row;
    
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            cin >> arr[i][j];
    
    col = 0;
    row = 0;
    
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(arr[i][j] > arr[col][row])
            {
                col = i;
                row = j;
            }
        }
    }
    
    cout << arr[col][row] << '\n';
    cout << col+1 << ' ' << row+1;
    
    return 0;
}
