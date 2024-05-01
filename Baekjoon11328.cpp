#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int count[26];
    string input;
    string trans;
    int test;
    bool IsAble = true;

    cin >> test;
    while (test--)
    {
        memset(count, 0, sizeof(count));
        input.clear();
        trans.clear();
        IsAble = true;

        cin >> input >> trans;

        if (input.length() != trans.length())
        {
            IsAble = false;
        }
        else
        {
            for (int i = 0; i < input.length(); i++)
                count[input[i] - 'a']++;

            for (int i = 0; i < trans.length(); i++)
            {
                if (!count[trans[i] - 'a'])
                {
                    IsAble = false;
                    break;
                }

                count[trans[i] - 'a']--;
            }
        }

        if (IsAble)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }

    return 0;
}