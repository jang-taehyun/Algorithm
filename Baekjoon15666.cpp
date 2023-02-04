/*
problem : n���� element�� ���� ���� array���� �ߺ��� ����Ͽ� m���� ��� ��������� non-decreasing order�� ���ĵ� �������� �ߺ����� ��� ����϶�.
input : ���� array, �� element�� ���� m
output : m���� �ߺ��� ����Ͽ� ���� non-decreasing order�� ���ĵ� ������

idea : ���� array�� non-decreasing order�� ������ �� DFS ������� Ž���Ͽ� m���� ����.
- non-promising ���� : ������ ������� ������ ���� ������� ������ ���� ���
  -> ���� level���� ������ �� ���ڿ� ���� �� ���ڰ� ���� ��
*/
#include <iostream>
#include <algorithm>
using namespace std;

int input[8];    // n���� element�� ���� ���� input == array
int length;      // ���� array�� ���� length == n
int choose;      // �� element�� ���� choose == m
int output[8];   // m���� ��� ���� ���� output

void DFS(int currentCount, int startIndex)
{
    // m���� ��� ����ٸ�, ���� output ��� �� Ž�� ����
    if (currentCount == choose)
    {
        for (int i = 0; i < choose; i++)
            cout << output[i] << ' ';
        cout << '\n';

        return;
    }

    // ���� level���� ������ �� ���� lastChooseNumber
    int lastChooseNumber = 0;

    // ���� array�� DFS ������� Ž���ϸ鼭 m���� ����.
    for (int i = startIndex; i < length; i++)
    {
        // non-promising ���� : ���� level���� ������ �� ���ڿ� ���� �� ���ڰ� ���� ���
        if (lastChooseNumber != input[i])
        {
            // lastChooseNumber�� ���� ���ڷ� ������Ʈ
            lastChooseNumber = input[i];

            // ���� ���ڸ� output�� �ְ� DFS ������� ���� array�� Ž��
            output[currentCount] = input[i];
            DFS(currentCount + 1, i);
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

    // ���� array�� DFS ������� Ž���ϸ鼭 m���� ��� ���� output �����
    DFS(0, 0);

    return 0;
}