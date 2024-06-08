#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int res;
    int tmp;
    
    while(1)
    {
        cin >> input;
        if("0" == input)
            break;
        
        res = 1;
        for(int i=0; i<input.length(); i++)
        {
            switch(input[i])
            {
                case '0':
                    res += 4;
                    break;
                case '1':
                    res += 2;
                    break;
                default:
                    res += 3;
                    break;
            }
            
            res++;
        }
        
        cout << res << '\n';
    }
    
    return 0;
}
