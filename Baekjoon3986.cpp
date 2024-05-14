#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    stack<char> storage;
    string input;
    int res = 0;

    cin >> test;
    while (test--)
    {
        while (!storage.empty())
            storage.pop();

        cin >> input;

        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == 'A')
            {
                if (!storage.empty() && storage.top() == 'A')
                    storage.pop();
                else
                    storage.push(input[i]);
            }
            else
            {
                if (!storage.empty() && storage.top() == 'B')
                    storage.pop();
                else
                    storage.push(input[i]);
            }
        }

        if (storage.empty())
            res++;
    }

    cout << res;

    return 0;
}