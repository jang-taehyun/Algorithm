#include <iostream>
#include <string>
using namespace std;

string input;
int BuyCount = 0;
int NumCount[10];

void BuyNumber()
{
    for (int i = 0; i < 10; i++)
        NumCount[i]++;
    BuyCount++;
}

int main()
{
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (input[i] - '0' == j)
            {
                if (!NumCount[j])
                {
                    if (j == 6 && NumCount[9])
                    {
                        NumCount[9]--;
                    }
                    else if (j == 9 && NumCount[6])
                    {
                        NumCount[6]--;
                    }
                    else
                    {
                        BuyNumber();
                        NumCount[j]--;
                    }
                }
                else
                {
                    NumCount[j]--;
                }
                break;
            }
        }
    }

    cout << BuyCount;

    return 0;
}