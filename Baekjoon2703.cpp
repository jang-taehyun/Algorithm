#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string input, res;
    char trans[26];
    
    cin >> n;
    cin.ignore();
    
    while(n--)
    {
        getline(cin, input);
        for(int i=0; i<26; i++)
            cin >> trans[i];
        cin.ignore();
        
        for(int i=0; i<input.length(); i++)
        {
            if(input[i] >= 'A' && input[i] <= 'Z')
                res += trans[input[i] - 'A'];
            else
                res += input[i];
        }
        
        cout << res << '\n';
        
        input = "";
        res = "";
    }
    
    return 0;
}
