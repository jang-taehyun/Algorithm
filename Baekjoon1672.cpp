#include <iostream>
#include <stack>
using namespace std;

int Convert(char p)
{
    switch(p)
    {
        case 'A':
            return 0;
        case 'G':
            return 1;
        case 'C':
            return 2;
        case 'T':
            return 3;
    }
}

int main()
{
    int len;
    char a1, a2;
    stack<char> input;
    
    // A = 0, G = 1, C = 2, T = 3
    char board[4][4] = {
        'A', 'C', 'A', 'G',
        'C', 'G', 'T', 'A',
        'A', 'T', 'C', 'G',
        'G', 'A', 'G', 'T'
    };
    
    cin >> len;
    while(len--)
    {
        cin >> a1;
        input.push(a1);
    }
    
    while(input.size() > 1)
    {
        a2 = input.top();
        input.pop();
        a1 = input.top();
        input.pop();
        
        input.push(board[Convert(a1)][Convert(a2)]);
    }
    
    cout << input.top();
    
    return 0;
}
