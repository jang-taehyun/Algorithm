#include <iostream>
#include <string>
using namespace std;

typedef unsigned int uint;

int main()
{
    string operand1;
    uint num, operand2;

    cin >> operand1;
    cin >> operand2;

    for (int i = 0; i < 100; i++)
    {
        operand1[operand1.length() - 2] = '0' + (i / 10);
        operand1[operand1.length() - 1] = '0' + (i % 10);

        num = stoul(operand1);

        if (!(num % operand2))
        {
            cout << operand1[operand1.length() - 2] << operand1[operand1.length() - 1];
            break;
        }
    }

    return 0;
}