#include <iostream>
using namespace std;

int main()
{
    double price, gram;
    int count;
    double tmp, res;
    
    cout.precision(2);
    cout << fixed;
    
    cin >> price >> gram;
    cin >> count;
    
    res = (price / gram) * 1000.f;
    
    while(count--)
    {
        cin >> price >> gram;
        tmp = (price / gram) * 1000.f;
        
        if(tmp < res)
            res = tmp;
    }
    
    cout << res;
    
    return 0;
}
