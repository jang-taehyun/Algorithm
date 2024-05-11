#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q;
    bool flag = true;
    int count;

    cin >> count;
    for (int i = 0; i < count; i++)
        q.push(i + 1);

    while (q.size() != 1)
    {
        flag = !flag;

        if (flag)
            q.push(q.front());

        q.pop();
    }

    cout << q.front();

    return 0;
}