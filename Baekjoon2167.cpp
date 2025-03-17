#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, r;
    int arr[300][300] = { 0, };
    int y1, x1, y2, x2;
    int test;
    int res = 0;

    cin >> c >> r;
    for (int i = 0; i < c; ++i)
        for (int j = 0; j < r; ++j)
            cin >> arr[i][j];

    cin >> test;
    while (test--)
    {
        cin >> y1 >> x1 >> y2 >> x2;

        --y1;
        --x1;
        --y2;
        --x2;

        for (int i = y1; i <= y2; ++i)
            for (int j = x1; j <= x2; ++j)
                res += arr[i][j];

        cout << res << '\n';

        res = 0;
    }

    return 0;
}
