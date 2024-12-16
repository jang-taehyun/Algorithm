#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string input;
    bool IsExist[26] = { false, };
    bool IsRight = true;
    
    while(1)
    {
        getline(cin, input);
        
        if("*" == input)
            break;
        
        for(int i=0; i<input.length(); i++)
        {
            if(' ' == input[i])
                continue;
            
            IsExist[input[i] - 'a'] = true;
        }
        
        for(int i=0; i<26; i++)
            if(!IsExist[i])
            {
                IsRight = false;
                break;
            }
        
        cout << (IsRight ? "Y" : "N") << '\n';
        memset(IsExist, 0, sizeof(IsExist));
        IsRight = true;
    }
    
    return 0;
}
