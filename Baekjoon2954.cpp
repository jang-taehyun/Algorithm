#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    getline(cin, input);
    
    for(int i=0; i<input.length(); i++)
    {
        cout << input[i];
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i'
          || input[i] == 'o' || input[i] == 'u')
            i+=2;
    }
    
    return 0;
}
