#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    stack<char> storage;
    bool IsComplete = true;

    while (1)
    {
        IsComplete = true;
        input = "";
        while (!storage.empty())
            storage.pop();

        getline(cin, input);
        if ("." == input)
            break;

        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '[' || input[i] == '(')
            {
                storage.push(input[i]);
            }
            else if (input[i] == ']' || input[i] == ')')
            {
                if (storage.empty())
                {
                    IsComplete = false;
                    break;
                }
                if ((input[i] == ']' && storage.top() != '[') ||
                    (input[i] == ')' && storage.top() != '('))
                    break;

                storage.pop();
            }
        }

        if (!storage.empty())
            IsComplete = false;

        cout << (IsComplete ? "yes" : "no") << '\n';
    }

    return 0;
}