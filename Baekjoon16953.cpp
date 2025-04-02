#include <iostream>
#include <queue>
using namespace std;

typedef long long LL;

LL BFS(LL s, LL t);

int main()
{
    LL start, target;
    cin >> start >> target;
    
    cout << BFS(start, target);
    
    return 0;
}

LL BFS(LL s, LL t)
{
    queue<LL> q;
    LL QueueSize;
    LL cur, len = 1;
    
    q.push(s);
    
    while(!q.empty())
    {
        QueueSize = q.size();
        while(QueueSize--)
        {
            cur = q.front();
            q.pop();
            
            if(t == cur)
                return len;
            
            if(cur*2 <= t)
                q.push(cur * 2);
            if(cur*10+1 <= t)
                q.push(cur * 10 + 1);
        }
        
        ++len;
    }
    
    return -1;
}
