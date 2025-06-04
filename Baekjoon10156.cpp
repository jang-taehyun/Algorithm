#include <iostream>
using namespace std;

int main()
{
    int op1, mul, cur;
    cin >> op1 >> mul >> cur;
    cout << ((op1 * mul) > cur ? ((op1 * mul) - cur) : 0);
    
    return 0;
}
