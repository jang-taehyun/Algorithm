#include <iostream>
using namespace std;

int main()
{
    int row, column;
    char board[50][50] = { 0, };
    int building=0, parked=0, empty=0;
    int res[5] = { 0, };
    
    cin >> column >> row;
    for(int i=0; i<column; i++)
        for(int j=0; j<row; j++)
            cin >> board[i][j];
    
    for(int i=0; i<column-1; i++)
    {
        for(int j=0; j<row-1; j++)
        {
            building = 0;
            parked = 0;
            empty = 0;
            
            for(int k=i; k<i+2; k++)
                for(int l=j; l<j+2; l++)
                {
                    if('.' == board[k][l])
                        empty++;
                    else if('#' == board[k][l])
                        building++;
                    else
                        parked++;
                }
            
            if(building)
                continue;
            
            res[parked]++;
        }
    }
    
    for(int i=0; i<5; i++)
        cout << res[i] << '\n';
    
    return 0;
}
