#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int cnt, test;
    int price;
    string name;
    map<int, string> m;
    
    cin >> test;
    while(test--)
    {
        cin >> cnt;
        while(cnt--)
        {
            cin >> price >> name;
            m.insert(make_pair(price, name));
        }
        
        cout << m.rbegin()->second << '\n';
        m.clear();
    }
    
    return 0;
}
