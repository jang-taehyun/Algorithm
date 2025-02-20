#include <iostream>
using namespace std;

int main()
{
    int c, r;
    int board[20][20] = {0, };
    int top=0, bottom=0, right=0, left=0, front=0, back=0;
    int cx, cy;
    int command;
    int input, tmp;
    
    cin >> c >> r >> cx >> cy >> command;
    for(int i=0; i<c; i++)
        for(int j=0; j<r; j++)
            cin >> board[i][j];
    
    while(command--)
    {
        cin >> input;
        
        switch(input)
        {
            case 1:
                {
                    if(cy+1 >= r)
                        continue;
                    cy++;
                    
                    tmp = right;
                    right = top;
                    top = left;
                    left = bottom;
                    bottom = tmp;
                }
                break;
            case 2:
                {
                    if(cy-1 < 0)
                        continue;
                    cy--;
                    
                    tmp = left;
                    left = top;
                    top = right;
                    right = bottom;
                    bottom = tmp;
                }
                break;
            case 3:
                {
                    if(cx-1 < 0)
                        continue;
                    cx--;
                    
                    tmp = back;
                    back = top;
                    top = front;
                    front = bottom;
                    bottom = tmp;
                }
                break;
            case 4:
                {
                    if(cx+1 >= c)
                        continue;
                    cx++;
                    
                    tmp = front;
                    front = top;
                    top = back;
                    back = bottom;
                    bottom = tmp;
                }
                break;
        }
        
        if(!board[cx][cy])
        {
            board[cx][cy] = bottom;
        }
        else
        {
            bottom = board[cx][cy];
            board[cx][cy] = 0;
        }
            
        
        cout << top << '\n';
    }
    
    return 0;
}
