#include <iostream>
using namespace std;

int main()
{
    int cnt;
    int a, b;
    int res = 0;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> a >> b;
        res += (b % a);
    }
    
    cout << res;
    
    return 0;
}
