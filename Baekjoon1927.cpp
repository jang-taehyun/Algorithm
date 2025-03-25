#include <iostream>
#include <queue>
using namespace std;

struct comp
{
    bool operator()(const int& r1, const int& r2)
    {
        return (r1 > r2);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test;
    priority_queue<int, vector<int>, comp> q;
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
