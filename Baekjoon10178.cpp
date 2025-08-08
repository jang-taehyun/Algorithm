#include <iostream>
using namespace std;

int main()
{
    int cnt;
    int num, divider;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> num >> divider;
        cout << "You get " << num / divider << " piece(s) and your dad gets "
            << num % divider << " piece(s)." << '\n';
    }
    
    return 0;
}
