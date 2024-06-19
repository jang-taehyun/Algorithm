#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef unsigned int UINT;

int main()
{
    string name;
    vector<string> inputs;
    string res;
    string tmp;
    UINT cnt;
    UINT exist[26];
    UINT maxres=0;
    UINT middleres=1;
    
    cin >> name;
    cin >> cnt;
    for(int i=0; i<cnt; i++)
    {
        cin >> tmp;
        inputs.push_back(tmp);
    }
    
    sort(inputs.begin(), inputs.begin()+cnt);
    tmp = "LOVE";
    
    for(int i=0; i<inputs.size(); i++)
    {
        memset(exist, 0, sizeof(exist));
        middleres=1;
        
        for(int j=0; j<inputs[i].length(); j++)
            exist[inputs[i][j] - 'A']++;
        for(int j=0; j<name.length(); j++)
            exist[name[j] - 'A']++;
        
        for(int j=0; j<tmp.length(); j++)
            for(int k=j+1; k<tmp.length(); k++)
                middleres *= (exist[tmp[j] - 'A'] + exist[tmp[k] - 'A']);
        
        middleres %= 100;
        
        if(maxres < middleres || !i)
        {
            maxres = middleres;
            res = inputs[i];
        }
    }
    
    cout << res;
    
    return 0;
}
