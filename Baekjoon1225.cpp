#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input1, input2;
    int n1, n2;
    unsigned long long res = 0;

    cin >> input1;
    cin >> input2;

    for (unsigned long long i = 0; i < input1.length(); i++)
    {
        n1 = input1[i] - '0';
        for (int j = 0; j < input2.length(); j++)
        {
            n2 = input2[j] - '0';

            res += (unsigned long long)(n1 * n2);
        }
    }

    cout << res;

    return 0;
}