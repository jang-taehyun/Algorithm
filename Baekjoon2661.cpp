/*
problem : ���̰� n�̰� �� ��Ұ� 1, 2, 3 �� �ϳ��� ��������
          ������ ������ ������ �� ���� �κ� ������ �������� �ʴ� ���� ��
          ���� ���� ���� ��Ÿ���� ������ ���ض�.
input : ������ ���� n
output : ������ ������ ������ �� ���� �κ� ������ �������� �ʴ� ���� �� ���� ���� ���� ��Ÿ���� ����

idea
- root�� �� �ʱ� ����, node�� ������� �ϼ��� ����, level�� �� Ƚ���� �ǹ��ϴ� tree�� �����.
- tree�� DFS ������� Ž��
- non-promising ���� : �ڿ������� �����Ͽ� ���̰� (�� Ƚ��/2)�� �ɶ����� �ݺ��� ������ ������ ���� ������ ���
*/
#include <iostream>
#include <string>
using namespace std;

int ChooseCount;

// promising �˻�
bool Promising(string current)
{
    for (int i = 1; i <= current.length() / 2; i++)
        if (current.substr(current.length() - i, i) == current.substr(current.length() - 2 * i, i))
            return false;
    return true;
}

// tree Ž��
bool DFS(string current, int cnt)
{
    if (!Promising(current))
        return false;

    // ��� ����ٸ� ��� �� Ž�� �ߴ�
    if (cnt >= ChooseCount)
    {
        cout << current;
        return true;
    }

    // Ž��
    for (int i = 1; i <= 3; i++)
        if (DFS(current + to_string(i), cnt + 1))
            return true;

    // ã�� �������Ƿ� false ��ȯ
    return false;
}

int main()
{
    // ������ ���� �Է�
    cin >> ChooseCount;

    // tree Ž��
    for (int i = 1; i <= 3; i++)
        if (DFS(to_string(i), 1))
            break;

    return 0;
}