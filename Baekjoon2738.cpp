#include <iostream>
using namespace std;

int main()
{
    int a[100][100];
    int b[100][100];
    int column, row;
    
    cin >> column >> row;
    for(int i=0; i<column; i++)
        for(int j=0; j<row; j++)
            cin >> a[i][j];
    for(int i=0; i<column; i++)
        for(int j=0; j<row; j++)
            cin >> b[i][j];
    
    for(int i=0; i<column; i++)
    {
        for(int j=0; j<row; j++)
            cout << a[i][j] + b[i][j] << ' ';
        cout << '\n';
    }
    
    return 0;
}
