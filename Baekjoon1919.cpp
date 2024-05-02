#include <iostream>
#include <string>
#define MAX(x, y) (x) > (y) ? (x) : (y)
#define MIN(x, y) (x) < (y) ? (x) : (y)
using namespace std;

string input1, input2;
int alphaCount1[26];
int alphaCount2[26];
int res = 0;

int main()
{
    int maxcount, mincount;

    cin >> input1 >> input2;

    for (int i = 0; i < input1.length(); i++)
        alphaCount1[input1[i] - 'a']++;
    for (int i = 0; i < input2.length(); i++)
        alphaCount2[input2[i] - 'a']++;

    for (int i = 0; i < 26; i++)
    {
        if (alphaCount1[i] != alphaCount2[i])
        {
            maxcount = MAX(alphaCount1[i], alphaCount2[i]);
            mincount = MIN(alphaCount1[i], alphaCount2[i]);

            res += (maxcount - mincount);
        }
    }

    cout << res;

    return 0;
}