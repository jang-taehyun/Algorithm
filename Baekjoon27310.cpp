#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[33] = {0, };
    int underbar = 0;
    int len;
    
    cin >> input;
    
    len = strlen(input);
    for(int i=1; i<len-1; ++i)
        if('_' == input[i])
            ++underbar;
    
    cout << (len + 2 + underbar * 5);
    
    return 0;
}
