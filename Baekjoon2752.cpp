/*
problem : 3���� ���ڸ� ������������ sort�ض�.
input : 3���� ����
output : 3���� ���ڸ� ������������ sort

idea : 3���� ���ڸ� ���� ���� �˰����� �̿��� ������������ sort
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