#include <iostream>
using namespace std;

int main()
{
    int cnt, price;
    cin >> cnt >> price;
    cout << (((cnt * 100) >= price) ? "Yes" : "No");
    
    return 0;
}
