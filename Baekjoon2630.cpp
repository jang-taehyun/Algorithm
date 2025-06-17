#include <iostream>
using namespace std;

int board[128][128] = {0, };
int res0=0, res1=0;

void Divide(int y, int x, int l)
{
    bool IsFull = true;
    int pivot = board[y][x];
    
    for(int i=y; i<y+l; ++i)
    {
        if(!IsFull)
            break;
        
        for(int j=x; j<x+l; ++j)
            if(pivot != board[i][j])
            {
                IsFull = false;
                break;
            }
    }
    
    if(IsFull)
    {
        if(!pivot)
            ++res0;
        else
            ++res1;
        
        return;
    }
    
    Divide(y, x, l/2);
    Divide(y+l/2, x, l/2);
    Divide(y, x+l/2, l/2);
    Divide(y+l/2, x+l/2, l/2);
}

int main()
{
    int len;
    
    cin >> len;
    for(int i=0; i<len; ++i)
        for(int j=0; j<len; ++j)
            cin >> board[i][j];
    
    Divide(0, 0, len);
    cout << res0 << '\n' << res1;
    
    return 0;
}
