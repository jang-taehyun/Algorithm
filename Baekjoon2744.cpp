#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int tmp = abs('A' - 'a');
    char output;
    
    cin >> input;
    for(int i=0; i<input.length(); i++)
    {
        if(input[i] >= 'A' && input[i] <= 'Z')
            output = input[i] + tmp;
        else
            output = input[i] - tmp;
        
        cout << output;
    }
    
    return 0;
}
