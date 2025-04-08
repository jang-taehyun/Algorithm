#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[51] = {0, };
    int res = 10;
    
    cin >> input;
    
    for(int i=1; i<strlen(input); ++i)
        res += (input[i] == input[i-1] ? 5 : 10);
    
    cout << res;
    
    return 0;
}
