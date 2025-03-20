#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    int nh, ns;
    set<string> not_see;
    set<string> not_heard;
    set<string> not_see_heard;
    set<string>::iterator iter;
    string input;
    
    cin >> nh >> ns;
    for(int i=0; i<nh; ++i)
    {
        cin >> input;
        not_heard.insert(input);
    }
    
    for(int i=0; i<ns; ++i)
    {
        cin >> input;
        not_see.insert(input);
    }
    
    if(nh > ns)
    {
        for(iter = not_heard.begin(); iter != not_heard.end(); ++iter)
        {
            if(not_see.end() != not_see.find(*iter))
                not_see_heard.insert(*iter);
        }
    }
    else
    {
        for(iter = not_see.begin(); iter != not_see.end(); ++iter)
        {
            if(not_heard.end() != not_heard.find(*iter))
                not_see_heard.insert(*iter);
        }
    }
    
    cout << not_see_heard.size() << '\n';
    for(iter = not_see_heard.begin(); iter != not_see_heard.end(); ++iter)
        cout << *iter << '\n';
        
    return 0;
}
