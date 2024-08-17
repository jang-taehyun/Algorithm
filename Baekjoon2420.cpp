#include <iostream>
using namespace std;

int main()
{
    long long n, m;
    long long res;
    
    cin >> n >> m;
    
    res = n-m;
    if(res < 0)
        res *= (long long)-1;
    
    cout << res;
}
