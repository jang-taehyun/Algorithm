#include <iostream>
using namespace std;

int main()
{
    int cur, minus;
    char command;
    
    while(1)
    {
        cin >> cur >> command >> minus;
        if(!cur && command == 'W' && !minus)
            break;
        
        if(command == 'D')
            cout << cur+minus << '\n';
        else
        {
            if(cur-minus < -200)
                cout << "Not allowed" << '\n';
            else
                cout << cur-minus << '\n';
        }
    }
    
    return 0;
}
