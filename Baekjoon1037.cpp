/*
problem : ���� k�� ������� ��� �־����� ��, k�� ���ض�.
input : n���� �����
output : n���� ������� ��� ������ �ִ� ���� k

idea
- n���� ���ڸ� ������������ sort
- ù��° ���ڿ� ������ ���ڸ� ���� k�� ���Ѵ�.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int cnt;                // ����� ����
    int input[50];          // �����

    // �־��� ������ ������ ���ڵ��� �Է�
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
        cin >> input[i];

    // ������������ sort
    sort(input, input + cnt);

    // ����� ���
    cout << input[0] * input[cnt - 1];

    return 0;
}