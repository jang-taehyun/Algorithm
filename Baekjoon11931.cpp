#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int len, tmp;
    priority_queue<int> q;
    
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
