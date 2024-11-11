#include <iostream>
using namespace std;

int main()
{
    int e, f, c;
    int tmp1, tmp2;
    int res = 0;
    
    cin >> e >> f >> c;
    while((e + f) / c)
    {
        res += ((e + f) / c);
        tmp1 = (e + f) / c;
        tmp2 = (e + f) % c;
        
        e = tmp1;
        f = tmp2;
    }
    
    cout << res;
    
    return 0;
}
