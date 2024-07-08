#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    string secret;
    string res;
    int idx=0;
    int adder;
    char tmp;
    
    getline(cin, input);
    cin >> secret;
    
    for(int i=0; i<input.length(); i++)
    {
        if(input[i] == ' ')
        {
            idx++;
            idx %= secret.length();
            res += input[i];
            continue;
        }
        
        adder = secret[idx] - 'a' + 1;
        tmp = input[i] - adder;
        
        if(tmp < 'a')
            tmp += 26;
        res += tmp;
        
        idx++;
        idx %= secret.length();
    }
    
    cout << res;
    
    return 0;
}
