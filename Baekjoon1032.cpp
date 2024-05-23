#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> inputs;
    int len;
    string input;
    char compare;
    bool IsEqual = true;

    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> input;
        inputs.push_back(input);
    }

    for (int i = 0; i < inputs[0].length(); i++)
    {
        IsEqual = true;

        compare = inputs[0][i];
        for (int j = 1; j < len; j++)
        {
            if (compare != inputs[j][i])
            {
                IsEqual = false;
                break;
            }
        }

        if (IsEqual)
            cout << compare;
        else
            cout << '?';
    }

    return 0;
}