#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int zero = 0, one = 0;
    char prev;
    
    cin >> input;
    
    prev = input[0];
    input[0] == '0' ? ++zero : ++one;
    for(int i=1; i<input.length(); ++i)
        if(prev != input[i])
        {
            input[i] == '0' ? ++zero : ++one;
            prev = input[i];
        }
    
    cout << (zero < one ? zero : one);
    
    return 0;
}
