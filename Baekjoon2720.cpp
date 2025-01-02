#include <iostream>
using namespace std;

int main()
{
    int test;
    int input;
    int divider[4] = {25, 10, 5, 1};
    
    cin >> test;
    while(test--)
    {
        cin >> input;
        
        for(int i=0; i<4; i++)
        {
            cout << (input / divider[i]) << ' ';
            input %= divider[i];
        }
        cout << '\n';
    }
    
    return 0;
}
