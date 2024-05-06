/*
- 현재 탐색하고 있는 건물을 볼 수 있는 건물들의 개수를 더해간다.
*/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int count;
    long long building[80000];
    stack<long long> storage;
    long long res = 0;

    cin >> count;
    for (int i = 0; i < count; i++)
        cin >> building[i];

    for (int i = 0; i < count; i++)
    {
        // 자신보다 큰 수가 나올 때까지 pop
        while (!storage.empty() && building[i] >= building[storage.top()])
            storage.pop();

        // 현재 탐색하고 있는 건물을 볼 수 있는 건물들의 개수를 더한다.
        res += storage.size();

        // 현재 index를 push
        storage.push(i);
    }

    cout << res;

    return 0;
}