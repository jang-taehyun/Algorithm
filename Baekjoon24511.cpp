#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len, n;
    queue<int> res;
    deque<int> d;
    
    cin >> len;
    for(int i=0; i<len; ++i)
    {
        cin >> n;
        if(!n)
            res.push(i);
    }
    
    for(int i=0; i<len; ++i)
    {
        cin >> n;
        
        if(!res.empty() && res.front() == i)
        {
            d.push_front(n);
            res.pop();
        }
    }
    
    cin >> len;
    for(int i=0; i<len; ++i)
    {
        cin >> n;
        d.push_back(n);
        res.push(d.front());
        d.pop_front();
    }
    
    while(!res.empty())
    {
        cout << res.front() << ' ';
        res.pop();
    }
    
    return 0;
}
