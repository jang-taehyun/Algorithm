#include <iostream>
#include <stack>
using namespace std;

typedef unsigned int UINT;

int main()
{
    stack<UINT> storage;
    UINT sum = 0;

    UINT count;
    UINT input;

    cin >> count;
    while (count--)
    {
        cin >> input;

        if (!input)
        {
            sum -= storage.top();
            storage.pop();
        }
        else
        {
            sum += input;
            storage.push(input);
        }
    }

    cout << sum;

    return 0;
}