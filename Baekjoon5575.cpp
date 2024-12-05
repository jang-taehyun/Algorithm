#include <iostream>
using namespace std;

int main()
{
    int arr[3][6];
    int res[3][3];
    
    for(int i=0; i<3; i++)
        for(int j=0; j<6; j++)
            cin >> arr[i][j];
    
    for(int i=0; i<3; i++)
    {
        for(int j=2; j>=0; j--)
        {
            if(arr[i][j] > arr[i][j+3])
            {
                res[i][j] = (arr[i][j+3] + 60) - arr[i][j];
                arr[i][j+2]--;
            }
            else
                res[i][j] = arr[i][j+3] - arr[i][j];
        }
    }
    
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            cout << res[i][j] << ' ';
        cout << '\n';
    }
    
    return 0;
}
