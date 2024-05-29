#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int len;
    string input;
    int count[26];
    bool IsNotChoose = true;
    char output;

    memset(count, 0, sizeof(count));

    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> input;
        count[input[0] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] >= 5)
        {
            if (IsNotChoose)
                IsNotChoose = false;

            output = 'a' + i;
            cout << output;
        }
    }

    if (IsNotChoose)
        cout << "PREDAJA";

    return 0;
}