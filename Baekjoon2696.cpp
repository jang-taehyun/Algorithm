#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test, len, input, mid, cnt;
    priority_queue<int> leftq;
    priority_queue<int, vector<int>, greater<int>> rightq;
    queue<int> res;
    
    cin >> test;
    while(test--)
    {
        cin >> len;

        for(int i=0; i<len; ++i)
        {
            cin >> input;
            
            if(!i)
            {
                mid = input;
                res.push(mid);
            }
            else
            {
                if(mid > input)
                    leftq.push(input);
                else
                    rightq.push(input);
            }
            
            if(i && !(i % 2))
            {
                if(leftq.size() != rightq.size())
                {
                    if(leftq.size() > rightq.size())
                    {
                        while(leftq.size() != rightq.size())
                        {
                            rightq.push(mid);
                            mid = leftq.top();
                            leftq.pop();
                        }
                    }
                    else
                    {
                        while(leftq.size() != rightq.size())
                        {
                            leftq.push(mid);
                            mid = rightq.top();
                            rightq.pop();
                        }
                    }
                }
                 
                res.push(mid);
            }
        }
        
        cnt = res.size();
        cout << cnt << '\n';
        for(int i=1; i<=cnt; ++i)
        {
            cout << res.front() << ' ';
            res.pop();
            
            if(!(i%10))
                cout << '\n';
        }
        
        while(!leftq.empty() && !rightq.empty())
        {
            leftq.pop();
            rightq.pop();
        }
    }
    
    return 0;
}
