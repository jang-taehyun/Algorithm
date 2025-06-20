#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len, cnt;
    int num;
    string name;
    map<int, string> m1;
    map<string, int> m2;
    map<int, string>::iterator iter1;
    map<string, int>::iterator iter2;
    int idx=1;
    
    cin >> len >> cnt;
    while(len--)
    {
        cin >> name;
        
        m1.insert(make_pair(idx, name));
        m2.insert(make_pair(name, idx));
        ++idx;
    }
    
    while(cnt--)
    {
        cin >> name;
        
        if('0' <= name[0] && name[0] <= '9')
        {
            iter1 = m1.find(stoi(name));
            cout << iter1->second << '\n';
        }
        else
        {
            iter2 = m2.find(name);
            cout << iter2->second << '\n';
        }
    }
    
    return 0;
}
