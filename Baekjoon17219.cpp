#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int count, find;
    map<string, string> m;
    string ID, PW;
    
    cin >> count >> find;
    while(count--)
    {
        cin >> ID >> PW;
        m.insert(make_pair(ID, PW));
    }
    
    while(find--)
    {
        cin >> ID;
        cout << m.find(ID)->second << '\n';
    }
    
    return 0;
}
