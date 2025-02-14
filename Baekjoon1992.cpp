#include <iostream>
#include <string>
using namespace std;

int len;
bool board[64][64] = {false, };
string res;

void recur(int sx, int sy, int l)
{
    bool prev, IsFinish = true;
    
    prev = board[sy][sx];
    for(int i=sy; i<sy+l; i++)
    {
        if(!IsFinish)
            break;
        
        for(int j=sx; j<sx+l; j++)
        {
            if(prev != board[i][j])
            {
                IsFinish = false;
                break;
            }
        }
    }
    
    if(IsFinish)
    {
        res += (prev ? "1" : "0");
        return;
    }
    
    res += "(";
    recur(sx, sy, l/2);
    recur(sx+l/2, sy, l/2);
    recur(sx, sy+l/2, l/2);
    recur(sx+l/2, sy+l/2, l/2);
    res += ")";
}


int main()
{
    string input;
    
    cin >> len;
    for(int i=0; i<len; i++)
    {
        cin >> input;
        for(int j=0; j<len; j++)
            board[i][j] = (input[j] == '1' ? true : false);
    }
    
    recur(0, 0, len);
    
    cout << res;
    
    return 0;
}
