#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test, cnt, flag;
    multiset<int> pq;
    set<int>::iterator iter;
    char command;
    
    cin >> test;
    while(test--)
    {
        cin >> cnt;
        while(cnt--)
        {
            cin >> command >> flag;
            
            if('I' == command)
                pq.insert(flag);
            
            if('D' == command)
            {
                if(flag > 0 && !pq.empty())
                {
                    iter = pq.end();
                    --iter;
                    pq.erase(iter);
                }
                else if(flag < 0 && !pq.empty())
                    pq.erase(pq.begin());
            }
        }
        
        if(!pq.empty())
        {
            iter = pq.end();
            --iter;
            cout << *iter << ' ' << *pq.begin() << '\n';
        }
        else
            cout << "EMPTY" << '\n';
        
        pq.clear();
    }
    
    return 0;
}
