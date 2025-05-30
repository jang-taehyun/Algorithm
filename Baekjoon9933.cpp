#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int cnt;
    string input, tmp;
    set<string> s;
    set<string>::iterator iter;
    vector<string> v;
    string res;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> input;
        s.insert(input);
        v.push_back(input);
    }
    
    for(int i=0; i<v.size(); ++i)
    {
        tmp = v[i];
        reverse(tmp.begin(), tmp.end());
        
        iter = s.find(tmp);
        
        if(iter != s.end())
        {
            res = *iter;
            break;
        }
    }
    
    cout << res.length() << ' ' << res[res.length()/2];
    
    return 0;
}
