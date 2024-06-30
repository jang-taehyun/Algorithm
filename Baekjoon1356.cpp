#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ULL;

int main()
{
    string input;
    ULL n1=1, n2=1;
    bool flag = false;
    
    cin >> input;
    
    for(int idx=1; idx<input.length(); idx++)
    {
        n1=1;
        n2=1;
        
        for(int i=0; i<idx; i++)
            n1 *= (input[i] - '0');
        for(int i=idx; i<input.length(); i++)
            n2 *= (input[i] - '0');
        
        if(n1 == n2)
        {
            flag = true;
            break;
        }
    }
    
    cout << (flag ? "YES" : "NO");
    
    return 0;
}
