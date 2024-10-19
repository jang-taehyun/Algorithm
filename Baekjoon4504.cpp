#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    
    cin >> n1;
    while(1)
    {
        cin >> n2;
        
        if(!n2)
            break;
        
        cout << n2;
        if(n2 % n1)
            cout << " is NOT a multiple of ";
        else
            cout << " is a multiple of ";
        cout << n1 << ".\n";
    }
    
    return 0;
}
