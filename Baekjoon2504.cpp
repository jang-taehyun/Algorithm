#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<string> storage;
    string input;
    string tmp1;
    int res = 0;
    int tmp = 0;
    bool IsCorrect = false;

    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        tmp1 = input[i];
        if (tmp1 == "[" || tmp1 == "(")
        {
            storage.push(tmp1);
        }
        else if (tmp1 == "]" || tmp1 == ")")
        {
            IsCorrect = false;
            tmp = 1;
            while (!storage.empty())
            {
                if ((tmp1 == "]" && storage.top() == "[") ||
                    (tmp1 == ")" && storage.top() == "("))
                {
                    IsCorrect = true;
                    storage.pop();
                    break;
                }
                else if ((tmp1 == "]" && storage.top() == "(") ||
                    (tmp1 == ")" && storage.top() == "["))
                {
                    cout << 0;
                    return 0;
                }
                else if (storage.top() != "(" && storage.top() != "[")
                {
                    tmp *= stoi(storage.top());
                    storage.pop();
                }
            }

            if (tmp1 == "]")
                tmp *= 3;
            else
                tmp *= 2;

            while (!storage.empty())
            {
                if (storage.top() == "[" || storage.top() == "(")
                    break;

                tmp += stoi(storage.top());
                storage.pop();
            }

            if (!IsCorrect)
            {
                cout << 0;
                return 0;
            }

            storage.push(to_string(tmp));
        }
    }

    if (storage.top() != "(" && storage.top() != "[")
    {
        res = stoi(storage.top());
        storage.pop();
    }

    if (storage.empty())
        cout << res;
    else
        cout << 0;

    return 0;
}