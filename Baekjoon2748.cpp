#include <iostream>
using namespace std;

typedef unsigned long long ULL;

int main()
{
    int target;
    ULL prev1 = 1, prev2 = 0, res;
    cin >> target;
    
    if(target >= 2)
    {
        for(int i=2; i<=target; i++)
        {
            res = prev1 + prev2;
            
            prev2 = prev1;
            prev1 = res;
        }
        cout << res;
    }
    else
    {
        cout << 1;
    }
    
    return 0;
}
