#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    priority_queue<int, vector<int>, greater<int>> q;
    int input;
    
    cin >> n;
    for(int i=0; i<n*n; ++i)
    {
        cin >> input;
        
        if(q.size() < n)
            q.push(input);
        else if(q.size() == n)
        {
            if(q.top() < input)
            {
                q.pop();
                q.push(input);
            }
        }
    }
    
    cout << q.top();
    
    return 0;
}
