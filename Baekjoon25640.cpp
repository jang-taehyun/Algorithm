#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[5] = {0, };
    char cmp[5] = {0, };
    int cnt;
    int res=0;
    
    cin >> input >> cnt;
    while(cnt--)
    {
        cin >> cmp;
        
        if(!strcmp(input, cmp))
            ++res;
    }
    
    cout << res;
    
    return 0;
}
