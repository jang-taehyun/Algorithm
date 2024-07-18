#include <iostream>
#include <string>
using namespace std;

typedef long long LL;

int main()
{
    string input;
    LL res=0;
    LL mul=1;
    LL tmp;
    
    while(1)
    {
        cin >> input;
        if("#" == input)
            break;
        
        for(int i=input.length()-1; i>=0; i--)
        {
            switch(input[i])
            {
                case '-':
                    tmp = 0;
                    break;
                case '\\':
                    tmp = 1;
                    break;
                case '(':
                    tmp = 2;
                    break;
                case '@':
                    tmp = 3;
                    break;
                case '?':
                    tmp = 4;
                    break;
                case '>':
                    tmp = 5;
                    break;
                case '&':
                    tmp = 6;
                    break;
                case '%':
                    tmp = 7;
                    break;
                default:
                    tmp = -1;
                    break;
            }
            
            res += (tmp * mul);
            mul *= (LL)8;
        }
        
        cout << res << '\n';
        
        res=0;
        mul=1;
    }
    
    return 0;
}
