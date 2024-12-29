#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    long long tmp;
    long long res=0;
    
    cin >> a >> b;
    
    if(a > b)
        tmp = a - b + 1;
    else
        tmp = b - a + 1;
    
    res = (a + b) * tmp / 2;
    cout << res;
    
    return 0;
}
