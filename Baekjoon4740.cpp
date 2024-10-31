#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    
    while(1)
    {
        getline(cin, input);
        
        if("***" == input)
            break;
        
        for(int i=input.length() - 1; i>=0; i--)
            cout << input[i];
        cout << '\n';
    }
    
    return 0;
}
