#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    string res;
    bool IsInvalid = false;
    
    while(1)
    {
        cin >> input;
        
        if("#" == input)
            break;
        
        for(int i=input.length() - 1; i > -1; i--)
        {
            switch(input[i])
            {
                case 'b':
                    res += "d";
                    break;
                case 'd':
                    res += "b";
                    break;
                case 'p':
                    res += "q";
                    break;
                case 'q':
                    res += "p";
                    break;
                case 'i': case 'o': case 'v':
                case 'w': case 'x':
                    res += input[i];
                    break;
                default:
                    IsInvalid = true;
                    break;
            }
            
            if(IsInvalid)
            {
                res = "INVALID";
                break;
            }
        }
        
        cout << res << '\n';
        
        res.clear();
        IsInvalid = false;
    }
    
    return 0;
}
