#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int cnt;
    string input;
    map<string, int> m;
    string::size_type idx;
    map<string, int>::iterator iter;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> input;
        
        idx = input.find('.');
        input.erase(0, idx+1);
        
        iter = m.find(input);
        if(m.end() == iter)
            m.insert(make_pair(input, 1));
        else
            iter->second++;
    }
    
    for(iter=m.begin(); iter != m.end(); ++iter)
        cout << iter->first << ' ' << iter->second << '\n';
    
    return 0;
}
