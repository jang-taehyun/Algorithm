#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int test;
    string input;
    bool IsExist[26];
    int sum=0;
    
    cin >> test;
    while(test--)
    {
        memset(IsExist, false, sizeof(IsExist));
        sum = 0;
        
        cin >> input;
        
        for(int i=0; i<input.length(); i++)
            IsExist[input[i] - 'A'] = true;
        for(int i=0; i<26; i++)
            if(!IsExist[i])
                sum += (int)('A' + i);
        
        cout << sum << '\n';
    }
    
    return 0;
}
