#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    string cmp = "UCPC";
    int idx=0;
    
    getline(cin, input);
    
    for(int i=0; i<input.length(); ++i)
        if(idx <= cmp.length() && input[i] == cmp[idx])
            ++idx;
    
    cout << (idx >= cmp.length() ? "I love UCPC" : "I hate UCPC");
    
    return 0;
}
