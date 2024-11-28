#include <iostream>
using namespace std;

int main()
{
    int period, k, m, km, mm;
    int res = 1;
    
    cin >> period >> k >> m >> km >> mm;
    
    while((km * res < k) || (mm * res < m))
        res++;
    
    cout << (period - res);
    
    return 0;
}
