#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[101] = {0, };
    int res = 1;
    
    cin >> input;
    for(int i=0; i<strlen(input); ++i)
        if(',' == input[i])
            ++res;
    
    cout << res;
    
    return 0;
}
