#include <iostream>
using namespace std;

int func1(int n)
{
    int tmp, res = 1;
    
    for(int i=1; i<=8; ++i)
    {
        tmp = (n - i) % 8;
        
        if(!tmp)
        {
            res = ((i > 5) ? (10 - i) : i);            
            break;
        }
    }
    
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << func1(n);
    
    return 0;
}
