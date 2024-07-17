#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    char board[20][200];
    int len;
    int idx=0;
    
    cin >> len;
    cin >> input;
    for(int i=0; i<input.length() / len; i++)
    {
        if(i%2)
        {
            for(int j=len-1; j>=0; j--)
                board[i][j] = input[idx++];
        }
        else
        {
            for(int j=0; j<len; j++)
                board[i][j] = input[idx++];
        }
    }
        
    
    for(int i=0; i<len; i++)
        for(int j=0; j<input.length() / len; j++)
            cout << board[j][i];
    
    return 0;
}
