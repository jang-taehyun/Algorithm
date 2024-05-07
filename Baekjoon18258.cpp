#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    list<int> q;
    string command;
    int test, input;

    cin >> test;
    while (test--)
    {
        cin >> command;

        if (command == "push")
        {
            cin >> input;
            q.push_back(input);
        }
        else if (command == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << '\n';
                q.pop_front();
            }
            else
                cout << -1 << '\n';
        }
        else if (command == "size")
            cout << q.size() << '\n';
        else if (command == "empty")
            cout << q.empty() << '\n';
        else if (command == "front")
        {
            if (!q.empty())
                cout << q.front() << '\n';
            else
                cout << -1 << '\n';
        }
        else if (command == "back")
        {
            if (!q.empty())
                cout << q.back() << '\n';
            else
                cout << -1 << '\n';
        }
    }

    return 0;
}