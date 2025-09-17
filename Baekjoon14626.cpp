#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int mul = 1;
    int res=0, tmp=0, idx=0;
    
    cin >> input;
    
    for(int i=0; i<input.length(); ++i)
    {
        if('*' != input[i])
        {
            mul = (i % 2 ? 3 : 1);
            tmp += (input[i] - '0') * mul;
            tmp %= 10;
        }
        else
            idx = i;
    }
    
    if(tmp)
    {
        mul = (idx % 2 ? 3 : 1);
        for(int i=1; i<10; ++i)
            if(!((i * mul + tmp) % 10))
            {
                res = i;
                break;
            }
    }
    
    cout << res;
    
    return 0;
}
