#include <iostream>
using namespace std;

int main()
{
    int cnt;
    int v, e;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> v >> e;
        cout << (e + 2 - v) << '\n';
    }
    
    return 0;
}
