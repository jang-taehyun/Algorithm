#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct comp
{
    bool operator()(const int& r1, const int& r2)
    {
        if(abs(r1) != abs(r2))
            return (abs(r1) > abs(r2));
        return (r1 > r2);
    }
};

int main()
{
    priority_queue<int, vector<int>, comp> q;
    int test;
    int input;
    
    cin >> test;
    while(test--)
    {
        cin >> input;
        
        if(input)
            q.push(input);
        else
        {
            cout << (q.empty() ? 0 : q.top()) << '\n';
            
            if(!q.empty())
                q.pop();
        }
    }
    
    return 0;
}
