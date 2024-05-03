#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    list<char> res;
    list<char>::iterator cursor;
    string input;
    int test;

    cin >> test;
    while (test--)
    {
        res.clear();
        input.clear();
        cursor = res.begin();

        cin >> input;

        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '-')
            {
                if (cursor != res.begin())
                    cursor = res.erase(--cursor);
            }
            else if (input[i] == '>')
            {
                if (cursor != res.end())
                    cursor++;
            }
            else if (input[i] == '<')
            {
                if (cursor != res.begin())
                    cursor--;
            }
            else
            {
                res.insert(cursor, input[i]);
            }
        }

        for (list<char>::iterator i = res.begin(); i != res.end(); i++)
            cout << *i;
        cout << '\n';
    }

    return 0;
}