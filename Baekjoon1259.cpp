#include <iostream>
#include <string>
using namespace std;

int main()
{
    int input;
    string convert;
    bool IsMatch = true;
    
    while(1)
    {
        IsMatch = true;
        
        cin >> input;
        if(!input)
            break;
        
        convert = to_string(input);
        for(int i=0; i<=convert.length()/2; i++)
        {
            if(convert[i] != convert[convert.length() - 1 - i])
            {
                IsMatch = false;
                break;
            }
        }
        
        cout << (IsMatch ? "yes" : "no") << '\n';
    }
    
    return 0;
}