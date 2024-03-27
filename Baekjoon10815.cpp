/*
problem : -10^7 ~ 10^7 ������ ���ڰ� �����ִ� ī�带 n�� ������ ���� ��,
          -10^7 ~ 10^7 ������ ���ڰ� �����ִ� ī�� m�� �� ������ �ִ� ī�带 ���ض�.
input : ������ �ִ� ī���� ���� n(1 ~ 5*10^5), ������ �ִ� ī�忡 ���� �ִ� ���ڵ�,
        ���� ī���� ���� m(1 ~ 5*10^5), ���� ī��鿡 ���� �ִ� ���ڵ�
output : -10^7 ~ 10^7 ������ ���ڰ� �����ִ� ī�� m�� �� ������ �ִ� ī��

idea
- n���� ���ڵ��� �����ϰ� ������������ ����
- m���� ���ڵ� �� 1���� �Էµ� ������ binary search�� �̿��� Ž��
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_HAVE 500000
using namespace std;

int Having[MAX_HAVE];                // ������ �ִ� ���� ī���
int HavingCount;                     // ������ �ִ� ���� ī���� ����

bool BinarySearch(int _target)
{
    int Start = 0;
    int Last = HavingCount - 1;
    int Middle;

    // start�� last�� �Ѿ�� �ߴ�
    while (Start <= Last)
    {
        Middle = (Start + Last) / 2;

        if (Having[Middle] == _target)
            return true;

        if (Having[Middle] < _target)
            Start = Middle + 1;
        else
            Last = Middle - 1;
    }

    // ã�� �������Ƿ� false ��ȯ
    return false;
}

int main()
{
    int PresentCount;                // ���õ� ���� ī���� ����
    int PresentNumber;               // ���õ� ���� ī��
    vector<bool> IsHave;             // ���õ� ���� ī�带 ������ �ִ��� ����
    bool result;                     // binary search �� ���

    // ������ �ִ� ī���� ���� ī�忡 ���� ���� �Է�
    cin >> HavingCount;
    for (int i = 0; i < HavingCount; i++)
        cin >> Having[i];

    // �Էµ� ���� ī����� ������������ ����
    sort(Having, Having + HavingCount);

    // ���õ� ī�� �� ������ �ִ� ���� ī�带 vector�� ����
    cin >> PresentCount;
    for (int i = 0; i < PresentCount; i++)
    {
        cin >> PresentNumber;

        result = BinarySearch(PresentNumber);
        IsHave.push_back(result);
    }

    // ����� ���
    for (int i = 0; i < PresentCount; i++)
        cout << IsHave[i] << ' ';

    return 0;
}