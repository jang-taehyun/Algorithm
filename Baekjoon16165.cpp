#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int teamNum, problemNum;
    string group, name;
    int people, flag;
    
    map<string, vector<string>> team;
    map<string, vector<string>>::iterator iter;
    vector<string> tmp;
    
    cin >> teamNum >> problemNum;
    while(teamNum--)
    {
        cin >> group >> people;
        
        while(people--)
        {
            cin >> name;
            tmp.push_back(name);
        }
        
        sort(tmp.begin(), tmp.end());
        
        team.insert(make_pair(group, tmp));
        
        tmp.clear();
    }
    
    while(problemNum--)
    {
        cin >> name >> flag;
        
        if(flag)
        {
            for(iter = team.begin(); iter != team.end(); ++iter)
            {
                if(find(iter->second.begin(), iter->second.end(), name) != iter->second.end())
                {
                    cout << iter->first << '\n';
                    break;
                }
            }
        }
        else
        {
            iter = team.find(name);
            
            for(int i=0; i<iter->second.size(); ++i)
                cout << iter->second[i] << '\n';
        }
    }
    
    return 0;
}
