#include <iostream>
using namespace std;

typedef unsigned long long ULL;

int main()
{
    ULL a, b;
    ULL chicken;
    ULL sum;
    
    cin >> a >> b >> chicken;
    
    sum = a + b;
    
    if(sum >= chicken + chicken)
        cout << (sum - (chicken + chicken));
    else
        cout << sum;
    
    return 0;
}
