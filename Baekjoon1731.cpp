#include <iostream>
using namespace std;

typedef unsigned int UINT;

int main()
{
    UINT len;
    UINT input[50];
    bool flag=false;
    UINT q;
    
    cin >> len;
    for(int i=0; i<len; i++)
        cin >> input[i];
    
    if(!(input[1] % input[0]) && !(input[2] % input[1]))
    {
        if(input[1] / input[0] == input[2] / input[1])
        {
            q = input[1] / input[0];
            flag = true;
        }
    }
    
    if(!flag)
        q = input[1] - input[0];
    
    cout << (flag ? input[len-1] * q : input[len-1] + q);
    
    return 0;
}
