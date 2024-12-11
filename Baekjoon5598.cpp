#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    
    cin >> input;
    for(int i=0; i<input.length(); i++)
    {
        if(input[i] - 3 >= 'A' && input[i] - 3 <= 'Z')
            cout << (char)(input[i] - 3);
        else
            cout << (char)(input[i] - 3 + 26);
    }
    
    return 0;
}
