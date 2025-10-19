#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int len, node;
    priority_queue<int, vector<int>, greater<int>> pq;
    int n1, n2, res=0;
    
    cin >> len;
    for(int i=0; i<len; ++i)
    {
        cin >> node;
        pq.push(node);
    }
    
    while(pq.size() > 1)
    {
        n1 = pq.top();
        pq.pop();
        
        n2 = pq.top();
        pq.pop();
        
        pq.push(n1 + n2);
        res += (n1 + n2);
    }
    
    cout << res;
}
