#include <iostream>
using namespace std;

int main()
{
    int a, b;
    
    while(1)
    {
        cin >> a >> b;
        if(!a && !b)
            break;
        
        if((a / b) && !(a % b))
            cout << "multiple" << '\n';
        else if((b / a) && !(b % a))
            cout << "factor" << '\n';
        else
            cout << "neither" << '\n';
    }
    
    return 0;
}
