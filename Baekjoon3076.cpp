#include <iostream>
using namespace std;

char board[100][100];
int r,c;
int a,b;
bool IsBlack = true;

int main()
{
    cin >> r >> c;
    cin >> a >> b;
    
    for(int i=0; i<r*a; i++)
        for(int j=0; j<c*b; j++)
            if(!board[i][j])
            {
                if(j == 0 && i > 0)
                    IsBlack = (board[i-1][j] == 'X' ? false : true);
                
                for(int k=i; k<i + a; k++)
                    for(int l=j; l<j + b; l++)
                        board[k][l] = (IsBlack ? 'X' : '.');
                
                IsBlack = !IsBlack;
            }
    
    for(int i=0; i<r*a; i++)
    {
        for(int j=0; j<c*b; j++)
            cout << board[i][j];
        cout << '\n';
    }
    
    return 0;
}
