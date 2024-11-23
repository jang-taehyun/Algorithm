#include <iostream>
using namespace std;

int main()
{
    int test, input;
    double res=0.0;
    double price[5] = {350.34, 230.90, 190.55, 125.30, 180.90};
    
    cout.precision(2);
    cout << fixed;
    
    cin >> test;
    while(test--)
    {
        for(int i=0; i<5; i++)
        {
            cin >> input;
            res += ((double)input * price[i]);
        }
        
        cout << '$' << res << '\n';
        
        res = 0.0;
    }
    
    return 0;
}
