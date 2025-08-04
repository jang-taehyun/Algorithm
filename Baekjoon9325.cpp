#include <iostream>
using namespace std;

int main()
{
    int cnt1;
    int cnt2, num, price;
    int sum;
    
    cin >> cnt1;
    while(cnt1--)
    {
        cin >> sum;
        cin >> cnt2;
        
        while(cnt2--)
        {
            cin >> num >> price;
            sum += (num * price);
        }
        
        cout << sum << '\n';
    }
    
    return 0;
}
