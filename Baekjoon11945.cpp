#include <iostream>
using namespace std;

int main()
{
    int c, r;
    char board[10][10] = {0, };
    char res[10][10] = {0, };
    
    cin >> c >> r;
    for(int i=0; i<c; ++i)
        for(int j=0; j<r; ++j)
        {
            cin >> board[i][j];
            res[i][j] = '0';
        }
            
    
    for(int i=0; i<c; ++i)
        for(int j=0; j<r; ++j)
            if(board[i][j] == '1')
                res[i][r-1-j] = '1';
    
    for(int i=0; i<c; ++i)
    {
        for(int j=0; j<r; ++j)
            cout << res[i][j];
        cout << '\n';
    }
        
    
    return 0;
}
