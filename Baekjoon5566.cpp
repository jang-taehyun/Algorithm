#include <iostream>
using namespace std;

int len, Count, input, cur = 0, res = 0;
int board[1000];
bool finish = false;

int main()
{
    cin >> len >> Count;
    
    for(int i=0; i<len; i++)
        cin >> board[i];
    
    for(int j=0; j<Count; j++)
    {
        cin >> input;
        
        if(finish)
            continue;
        
        cur += input;
        cur += board[cur];
        res++;
        
        if(cur >= len-1)
            finish = true;
    }
    
    cout << res;
    
    return 0;
}
