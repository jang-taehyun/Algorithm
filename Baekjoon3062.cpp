#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef unsigned long UL;

int main()
{
    UL test;
    UL tmp;
    UL sum = 0;
    string input;
    bool IsSame = true;
    
    cin >> test;
    while(test--)
    {
        cin >> input;
        
        tmp = stoul(input);
        sum += tmp;
        
        reverse(input.begin(), input.end());
        tmp = stoul(input);
        sum += tmp;
        
        input = to_string(sum);
        
        for(int i=0; i<input.length() / 2; i++)
            if(input[i] != input[input.length() - 1 - i])
            {
                IsSame = false;
                break;
            }
        
        cout << (IsSame ? "YES" : "NO") << '\n';
        
        IsSame = true;
        sum = 0;
    }
    
    return 0;
}
