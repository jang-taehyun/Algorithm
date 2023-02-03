/*
problem : n���� element�� ���� ���� array���� �ߺ��� ����Ͽ� m���� �� �� ���� ������ �ߺ����� ��� ����ض�.
input : ���� array, �ڿ��� m
output : �ߺ��� ����Ͽ� m���� �� �� ��������� ������

idea : ���� array�� non-decreasing order�� sort�� �� DFS ������� Ž���Ͽ� m���� ����.
- non-promising : �ߺ��� ������ ����� �� ��
  -> ���� level���� ������ ����� ���ڿ� ���� �� ���ڰ� ���� ��
*/
#include <iostream>
#include <algorithm>
using namespace std;

int input[7];    // n���� element�� ���� ���� input == array
int length;      // ���� array�� ���� length == n
int choose;      // �� element�� ���� choose == m
int output[7];   // m���� ��� ������� ���� output

void DFS(int currentCount)
{
    // m���� ��� ����ٸ�, ���� ��� �� Ž�� ����
    if (currentCount == choose)
    {
        for (int i = 0; i < choose; i++)
            cout << output[i] << ' ';
        cout << '\n';

        return;
    }

    // ���� level���� ������ ����� ���� lastChooseNumber
    int lastChooseNumber = 0;

    // ���� array���� DFS ������� element�� m�� ����.
    for (int i = 0; i < length; i++)
    {
        // non-promising ���� : ���� level���� ������ ����� ���ڿ� ���� �� ���ڰ� ���� ��
        if (input[i] != lastChooseNumber)
        {
            // lastChooseNumber�� ���� ���ڷ� update
            lastChooseNumber = input[i];

            // ���� ���ڸ� output�� �ְ�, ���� level�� �Ѿ Ž��
            output[currentCount] = input[i];
            DFS(currentCount + 1);
        }
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

    // ���� array�� DFS ������� Ž���� m���� ��� ���� �����
    DFS(0);

    return 0;
}