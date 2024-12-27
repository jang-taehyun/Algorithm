#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int tmp;
    
    while(1)
    {
        cin >> input;
        
        if("0" == input)
            break;
        
        while(input.length() > 1)
        {
            tmp = 0;
            for(int i=0; i<input.length(); i++)
                tmp += (input[i] - '0');
            
            input = to_string(tmp);
        }
        
        cout << input << '\n';
    }
    
    return 0;
}
