#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    vector<int> remain[10];
    int idx1, idx2, tmp;
    int test;

    remain[0].push_back(10);
    for (int i = 1; i < 10; i++)
    {
        tmp = i;
        remain[i].push_back(tmp);

        while (1)
        {
            tmp *= i;
            tmp %= 10;

            if (tmp == i)
                break;

            remain[i].push_back(tmp);
        }
    }

    cin >> test;
    while (test--)
    {
        cin >> a >> b;
        idx1 = a % 10;
        idx2 = b % remain[idx1].size();

        idx2--;
        if (idx2 < 0)
            idx2 = remain[idx1].size() - 1;

        cout << remain[idx1][idx2] << '\n';
    }

    return 0;
}