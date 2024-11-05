#include <iostream>
using namespace std;

int main()
{
    double first, persent, bound;
    int res = 0;
    
    while(cin >> first >> persent >> bound)
    {
        persent *= 0.01;
    
        while(first <= bound)
        {
            first += (first * persent);
            res++;
        }
    
        cout << res << '\n';
        res = 0;
    }
    
    return 0;
}
