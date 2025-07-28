#include <iostream>
#define PI 3.141592
using namespace std;

int main()
{
    int d1, d2;
    cin >> d1 >> d2;
    
    cout << fixed;
    cout.precision(6);
    
    cout << ((d1 * 2) + (2 * d2 * PI));
    
    return 0;
}
