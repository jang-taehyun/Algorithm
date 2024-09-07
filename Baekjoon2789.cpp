#include <iostream>
#include <string>
using namespace std;

bool IsErase[26];

int main()
{
    string EraseString = "CAMBRIDGE";
    string input;
    string res="";
    
    for(int i=0; i<EraseString.length(); i++)
        IsErase[EraseString[i] - 'A'] = true;
    
    cin >> input;
    for(int i=0; i<input.length(); i++)
        if(!IsErase[input[i] - 'A'])
            res += input[i];
    
    cout << res;
    
    return 0;
}
