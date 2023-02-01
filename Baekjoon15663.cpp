/*
problem : n���� element�� ���� ���� array���� �ߺ����� m���� �̾� increasing order�� sort�� ������ �ߺ����� ��� ����ض�.
input : ���� array, �ڿ��� m
output : ���� array���� �ߺ����� m���� �̾� increasing order�� sort�� ������ �ߺ����� ��� ���

idea : ���� array�� increasing order�� sort�� �� index 0��°���� �����Ͽ� DFS ������� m���� �̴´�.
- Backtracking�� non-promisin ����
  1) ���� node�� �̹� �̾Ҵٸ�, �ٽ� ���� �ʴ´�.
  2) ������ �̾Ҵ� ���ڿ� ���� ���� ���ڰ� ������, ���� �ʴ´�.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int input[8];      // n���� element�� ���� ���� input == array
int length;        // ���� array�� ���� length == n
int choose;        // ���� ������ ���� choose == m
bool isVisited[8]; // ���� index �湮 ���� isVisited
int output[8];     // m���� �̾� ���� ���� output

void DFS(int currentCount)
{
    // m���� ��� ����ٸ� ���� output�� ��� �� function ����
    if (currentCount == choose)
    {
        for (int i = 0; i < choose; i++)
            cout << output[i] << ' ';
        cout << '\n';

        return;
    }

    // ������ �̾Ҵ� ���� lastChooseNumber
    int lastChooseNumber = 0;

    // ���� node�� child node�� ��� Ž��
    for (int i = 0; i < length; i++)
    {
        // non-promising : ���� index�� �湮�Ͽ��� or ������ �̾Ҵ� ���ڿ� ���� �̾Ҵ� ���ڰ� ����.
        if (!isVisited[i] && lastChooseNumber != input[i])
        {
            // �湮 ǥ�� & lastChooseNumber�� i��° ���ڷ� ����
            isVisited[i] = true;
            lastChooseNumber = input[i];

            // output�� i��° ���� ����
            output[currentCount] = input[i];

            // child node Ž��
            DFS(currentCount + 1);

            // �湮 ǥ�� ����
            isVisited[i] = false;
        }
    }
}

int main()
{
    // input �Է�
    cin >> length >> choose;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    // ���� input�� increasing order�� sort
    sort(input, input + length);

    // DFS ������� Ž���Ͽ� m���� ����.
    DFS(0);

    return 0;
}