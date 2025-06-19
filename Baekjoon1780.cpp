#include <iostream>
using namespace std;

int n;
int board[2187][2187] = {0, };
int res1=0, res2=0, res3=0;

void Divide(int y, int x, int len)
{
    bool IsComplete = true;
    int pivot = board[y][x];
    
    for(int i=y; i<y+len; ++i)
    {
        if(!IsComplete)
            break;
        
        for(int j=x; j<x+len; ++j)
            if(pivot != board[i][j])
            {
                IsComplete = false;
                break;
            }
    }
    
    if(IsComplete)
    {
        if(pivot == -1)
            ++res1;
        else if(pivot == 0)
            ++res2;
        else
            ++res3;
        
        return;
    }
    
    Divide(y, x, len/3);
    Divide(y, x+len/3, len/3);
    Divide(y, x+((len/3) * 2), len/3);
    
    Divide(y+len/3, x, len/3);
    Divide(y+len/3, x+len/3, len/3);
    Divide(y+len/3, x+((len/3) * 2), len/3);
    
    Divide(y+((len/3) * 2), x, len/3);
    Divide(y+((len/3) * 2), x+len/3, len/3);
    Divide(y+((len/3) * 2), x+((len/3) * 2), len/3);
}

int main()
{
    cin >> n;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> board[i][j];
    
    Divide(0, 0, n);
    
    cout << res1 << '\n' << res2 << '\n' << res3;
    
    return 0;
}
