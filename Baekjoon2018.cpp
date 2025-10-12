#include <iostream>
using namespace std;

int main()
{
    long long len;
    long long left=1, right=2;
    long long comp1, comp2, comp3;
    int res = 1;
    
    cin >> len;
    
    while(left < len && right < len)
    {
        comp1 = right * (right + 1) / 2;
        comp2 = (left - 1) * left / 2;
        comp3 = comp1 - comp2;
        
        if(comp3 == len)
        {
            ++res;
            ++left;
        }
        else if(comp3 < len)
            ++right;
        else
            ++left;
    }
    
    cout << res;
    
    return 0;
}
