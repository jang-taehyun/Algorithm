#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int target, n;
    queue<int> q;
    stack<int> s;
    bool flag = false;
    
    cin >> target;
    for(int i=0; i<target; ++i)
    {
        cin >> n;
        q.push(n);
    }
    
    n = 1;
    while(!q.empty() || !s.empty())
    {
        if(!q.empty() && q.front() == n)
        {
            if(q.front() == target)
            {
                flag = true;
                break;
            }
            
            q.pop();
        }
        else if(!s.empty() && s.top() == n)
        {
            if(s.top() == target)
            {
                flag = true;
                break;
            }
            
            s.pop();
        }
        else
        {
            while(!q.empty() && q.front() != n)
            {
                s.push(q.front());
                q.pop();
            }
            
            if(q.empty())
            {
                while(!s.empty() && s.top() != n)
                    s.pop();
                
                if(!s.empty())
                {
                    if(s.top() == target)
                    {
                        flag = true;
                        break;
                    }
                    
                    s.pop();
                }
            }
            else if(q.front() == target)
            {
                flag = true;
                break;
            }
            else
                q.pop();
        }
        
        ++n;
    }
    
    cout << (flag ? "Nice" : "Sad");
    
    return 0;
}
