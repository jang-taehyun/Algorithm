#include <iostream>
#include <string>
using namespace std;

int main()
{
    string op;
    int a1, a2;
    int seq = 1;
    
    while(1)
    {
        cin >> a1 >> op >> a2;
        if("E" == op)
            break;
        
        cout << "Case " << seq << ": ";
        if(">" == op)
            cout << (a1 > a2 ? "true" : "false") << '\n';
        else if(">=" == op)
            cout << (a1 >= a2 ? "true" : "false") << '\n';
        else if("<" == op)
            cout << (a1 < a2 ? "true" : "false") << '\n';
        else if("<=" == op)
            cout << (a1 <= a2 ? "true" : "false") << '\n';
        else if("==" == op)
            cout << (a1 == a2 ? "true" : "false") << '\n';
        else if("!=" == op)
            cout << (a1 != a2 ? "true" : "false") << '\n';
        
        seq++;
    }
    
    return 0;
}
