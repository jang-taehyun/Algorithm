#include <iostream>
#include <map>
using namespace std;

typedef long long LL;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test;
    LL num;
    LL res1=0, res2=0;
    map<LL, LL> m;
    map<LL, LL>::iterator iter;
    
    cin >> test;
    while(test--)
    {
        cin >> num;
        
        iter = m.find(num);
        if(iter == m.end())
            m.insert(make_pair(num, 1));
        else
            iter->second++;   
    }
    
    for(iter = m.begin(); iter != m.end(); ++iter)
        if(iter->second > res2)
        {
            res1 = iter->first;
            res2 = iter->second;
        }
    
    cout << res1;
    
    return 0;
}
