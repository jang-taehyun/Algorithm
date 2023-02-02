/*
problem : n���� element�� ���� ���� array���� �ߺ��� ������� �ʰ� m���� �� �� non-decreasing order�� sort�� ������ ��� ����ض�.
input : ���� array, �ڿ��� m
output : ���� array���� �ߺ��� ������� �ʰ� m���� �̾� non-decreasing order�� sort�� ����

idea : ���� array�� non-decreasing order�� sort�� ��, backtracking�� �̿��� index 0��°���� �����Ͽ� DFS ������� Ž���Ѵ�.
- non-promising : ������ ���� ������ ���� ���� ������ ���� ��
  -> ���� level���� ���� Ž���ߴ� node�� ���� Ž���� node�� ���� ���
*/
#include <iostream>
#include <algorithm>
using namespace std;

int input[8];      // n���� element�� ���� ���� input == array
int length;        // ���� array�� ���� length == n
int choose;        // �� element�� ���� choose == m
int output[8];     // ���� array���� m���� ��� ���� ���� output

void DFS(int currentCount, int startIndex)
{
    // m���� ��� ����ٸ�, ���� output ��� �� Ž�� ����
    if (choose == currentCount)
    {
        for (int i = 0; i < choose; i++)
            cout << output[i] << ' ';
        cout << '\n';

        return;
    }

    // ���� level���� ���� Ž���ߴ� node�� lastChooseNode
    int lastChooseNode = 0;

    // startIndex���� �����Ͽ� DFS ������� Ž���� m���� ����.
    for (int i = startIndex; i < length; i++)
    {
        // non-promising ���� : ���� level���� ���� Ž���ߴ� node�� ���� Ž���� node�� ���� ���
        if (lastChooseNode != input[i])
        {
            // lastChooseNode�� ���� node�� ����
            lastChooseNode = input[i];

            // ���� node�� ���� output�� �ְ�, ���� level Ž��
            output[currentCount] = input[i];
            DFS(currentCount + 1, i + 1);
        }
    }
}

int main()
{
    // input �Է�
    cin >> length >> choose;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    // ���� input�� non-decreasing order�� sort
    sort(input, input + length);

    // DFS ������� m���� ��� ���� output �����
    DFS(0, 0);

    return 0;
}