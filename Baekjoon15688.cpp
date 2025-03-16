#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len, tmp;
    priority_queue<int, vector<int>, greater<int>> q;
    
    cin >> len;
    for(int i=0; i<len; ++i)
    {
        cin >> tmp;
        q.push(tmp);
    }

    for (int i=0; i<len; ++i)
    {
        cout << q.top() << '\n';
        q.pop();
    }

    return 0;
}
