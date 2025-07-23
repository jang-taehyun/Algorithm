#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, p;
    int res1=0, res2=0;
    
    cin >> a >> b >> c >> d >> p;
    
    res1 = a * p;
    res2 = b;
    
    if(c <= p)
        res2 += ((p-c) * d);
    
    cout << (res1 < res2 ? res1 : res2);
    
    return 0;
}
