#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

struct comp
{
    bool operator()(pair<int, int>& p1, pair<int, int>& p2)
    {
        if(p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first < p2.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int jewelCnt, bagCnt;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;    // first : price, second : weight
    multiset<int> bags;
    multiset<int>::iterator iter;
    int w, p;
    unsigned long long res = 0;
    
    cin >> jewelCnt >> bagCnt;
    
    for(int i=0; i<jewelCnt; ++i)
    {
        cin >> w >> p;
        pq.push(make_pair(p, w));
    }
    
    for(int i=0; i<bagCnt; ++i)
    {
        cin >> w;
        bags.insert(w);
    }
    
    while(!pq.empty() && !bags.empty())
    {
        p = pq.top().first;
        w = pq.top().second;
        pq.pop();
        
        iter = bags.lower_bound(w);
        if(bags.end() != iter)
        {
            bags.erase(iter);
            res += (unsigned long long)p;
        }
    }
    
    cout << res;
    
    return 0;
}
