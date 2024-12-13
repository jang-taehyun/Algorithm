#include <iostream>
#include <string>
using namespace std;

int main()
{
    int test;
    double n;
    string op;
    
    cout.precision(2);
    cout << fixed;
    
    cin >> test;
    while(test--)
    {
        cin >> n;
        getline(cin, op);
        
        for(int i=0; i<op.length(); i++)
        {
            if('@' == op[i])
                n *= (double)3;
            else if('%' == op[i])
                n += (double)5;
            else if('#' == op[i])
                n -= (double)7;
        }
        
        cout << n << '\n';
    }
    
    return 0;
}
