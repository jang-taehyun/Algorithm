#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    string::reverse_iterator iter;
    
    while(1)
    {
        getline(cin, input);
        
        if("END" == input)
            break;
        
        for(iter = input.rbegin(); iter != input.rend(); ++iter)
            cout << *iter;
        cout << '\n';
    }
    
    return 0;
}
