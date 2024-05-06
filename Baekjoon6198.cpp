/*
- ���� Ž���ϰ� �ִ� �ǹ��� �� �� �ִ� �ǹ����� ������ ���ذ���.
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
        // �ڽź��� ū ���� ���� ������ pop
        while (!storage.empty() && building[i] >= building[storage.top()])
            storage.pop();

        // ���� Ž���ϰ� �ִ� �ǹ��� �� �� �ִ� �ǹ����� ������ ���Ѵ�.
        res += storage.size();

        // ���� index�� push
        storage.push(i);
    }

    cout << res;

    return 0;
}