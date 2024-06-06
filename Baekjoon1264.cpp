#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int res = 0;

    while (1)
    {
        getline(cin, input);
        if (string::npos != input.find("#"))
            break;

        for (int i = 0; i < input.length(); i++)
        {
            switch (input[i])
            {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                res++;
                break;
            default:
                break;
            }
        }

        cout << res << '\n';
        res = 0;
    }

    return 0;
}