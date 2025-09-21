#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<string> s;
    int cnt, divider;
    char gerne;
    string input;
    
    cin >> cnt >> gerne;
    while(cnt--)
    {
        cin >> input;
        s.insert(input);
    }
    
    switch(gerne)
    {
        case 'Y':
            divider = 1;
            break;
        case 'F':
            divider = 2;
            break;
        default:
            divider = 3;
    }
    
    cout << (s.size() / divider);
    
    return 0;
}
