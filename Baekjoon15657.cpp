/*
problem : n���� element�� ���� ���� array���� �ߺ��� ����Ͽ� m���� ��� non-decreasing order�� ���ĵ� ������ ��� ����ض�.
input : ���� array, �ڿ��� m
output : �ߺ��� ����Ͽ� m���� ��� non-decreasing order�� ���ĵ� ����

idea : ���� array�� non-decreasing order�� ������ ��, DFS ������� Ž���ϸ鼭 m���� ��� ������ �����.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int input[8];    // n���� element�� ���� ���� input == array
int length;      // ���� array�� ���� length == n
int choose;      // �� element�� ���� choose == m
int output[8];   // m���� element�� ��� ������� ���� output

void DFS(int currentCount, int startNode)
{
    // m���� ��� ����ٸ� ���� ��� �� function ����
    if (currentCount == choose)
    {
        for (int i = 0; i < choose; i++)
            cout << output[i] << ' ';
        cout << '\n';

        return;
    }

    // startNode�� ��� child node�� DFS ������� Ž���ϸ鼭 m���� ����.
    // -> �̶� child node�� ���� index���� (n-1)��° index�����̴�.
    for (int i = startNode; i < length; i++)
    {
        output[currentCount] = input[i];
        DFS(currentCount + 1, i);
    }
}

int main()
{
    // input �Է�
    cin >> length >> choose;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    // ���� array�� non-decreasing order�� sort
    sort(input, input + length);

    // index 0��°���� ����� DFS ������� Ž���Ͽ� m���� ����.
    DFS(0, 0);

    return 0;
}