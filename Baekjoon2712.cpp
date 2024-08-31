#include <iostream>
#include <string>
using namespace std;

int main()
{
    int test;
    double n, res;
    string input;
    
    cin >> test;
    while(test--)
    {
        cin >> n >> input;
        
        cout << fixed;
        cout.precision(4);
        
        if("kg" == input)
        {
            res = 2.2046 * n;
            cout << res << " lb\n";
        }
        else if("lb" == input)
        {
            res = 0.4536 * n;
            cout << res << " kg\n";
        }
        else if("l" == input)
        {
            res = 0.2642 * n;
            cout << res << " g\n";
        }
        else if("g" == input)
        {
            res = 3.7854 * n;
            cout << res << " l\n";
        }
    }
    
    return 0;
}
