#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int test;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    long long sum = 0;
    long long len, input, n1, n2;
    
    cin >> test;
    while(test--)
    {
        cin >> len;
        while(len--)
        {
            cin >> input;
            q.push(input);
        }
        
        while(q.size() > 1)
        {
            n1 = q.top();
            q.pop();
            n2 = q.top();
            q.pop();
            
            sum += (n1 + n2);
            q.push(n1 + n2);
        }
        
        cout << sum << '\n';
        
        sum = 0;
        while(!q.empty())
            q.pop();
    }
    
    return 0;
}
