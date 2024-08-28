#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> res;
    stack<int> tmp;
    int n;
    int s;
    
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> s;
        
        while(s && !res.empty())
        {
            tmp.push(res.top());
            res.pop(); 
            s--;
        }
        
        res.push(i);
        
        while(!tmp.empty())
        {
            res.push(tmp.top());
            tmp.pop();
        }
    }
    
    while(!res.empty())
    {
        tmp.push(res.top());
        res.pop();
    }
    
    while(!tmp.empty())
    {
        cout << tmp.top() << ' ';
        tmp.pop();
    }
    
    return 0;
}
