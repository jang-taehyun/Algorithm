#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    int count;
    set<string, greater<string>> office;
    set<string, greater<string>>::iterator iter;
    string name, state;
    
    cin >> count;
    while(count--)
    {
        cin >> name >> state;
        
        if("enter" == state)
            office.insert(name);
        else
        {
            iter = office.find(name);
            if(office.end() != iter)
                office.erase(iter);
        }
    }
    
    for(iter = office.begin(); iter != office.end(); ++iter)
        cout << *iter << '\n';
    
    return 0;
}
