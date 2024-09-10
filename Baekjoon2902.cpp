#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    string res="";
    
    cin >> input;
    for(int i=0; i<input.length(); i++)
    {
        res += input[i];
        
        while(input[i] != '-' && i < input.length())
            i++;
    }
    
    cout << res;
    
    return 0;
}
