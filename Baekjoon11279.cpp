#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test;
    priority_queue<int> q;
    int input;
    
    cin >> test;
    while(test--)
    {
        cin >> input;
        
        if(!input)
        {
            if(!q.empty())
            {
                cout << q.top() << '\n';
                q.pop();
            }
            else
                cout << 0 << '\n';
        }
        else
            q.push(input);
    }
    
    return 0;
}
