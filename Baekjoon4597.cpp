#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int tmp = 0;
    
    while(1)
    {
        cin >> input;
        
        if("#" == input)
            break;
        
        for(int i=0; i<input.length() - 1; i++)
            if(input[i] == '1')
                tmp++;
        
        if(input[input.length() - 1] == 'e')
            input[input.length() - 1] = ((tmp % 2) ? '1' : '0');
        else
            input[input.length() - 1] = (!(tmp % 2) ? '1' : '0');
        
        cout << input << '\n';
        tmp = 0;
    }
    
    return 0;
}
