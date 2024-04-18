/*
problem : 3개의 숫자를 오름차순으로 sort해라.
input : 3개의 숫자
output : 3개의 숫자를 오름차순으로 sort

idea : 3개의 숫자를 선택 정렬 알고리즘을 이용해 오름차순으로 sort
*/
#include <iostream>
using namespace std;

int main()
{
    int input[3];
    int tmp;
    for (int i = 0; i < 3; i++)
        cin >> input[i];

    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (input[i] > input[j])
            {
                tmp = input[i];
                input[i] = input[j];
                input[j] = tmp;
            }
        }
    }

    for (int i = 0; i < 3; i++)
        cout << input[i] << ' ';

    return 0;
}