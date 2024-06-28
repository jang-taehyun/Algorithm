#include <iostream>
using namespace std;

typedef unsigned int uint;

int main()
{
    uint n;
    uint res=0;
    uint remove=1;
    
    cin >> n;
    
    while(n)
    {
        if(n < remove)
            remove = 1;
        
        n -= remove;
        remove++;
        
        res++;
    }
    
    cout << res;
    
    return 0;
}
