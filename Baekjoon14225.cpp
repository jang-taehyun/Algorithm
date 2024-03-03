/*
Problem : �Էµ� ������ ��� ������ ��, ���� �� ���� ���� ���� �ڿ����� ���ض�.
Input : ���� S
Output : ���� �� ���� ���� ���� �ڿ���

Idea
- ���� S�� ������������ �����Ѵ�.
- bruteforce�� �̿���, ���� S���� ���� �� �ִ� ��� ������ ���ϰ� �湮 ǥ�ø� �Ѵ�.
- �湮 ǥ�ø� �˻��� ���� �� ���� ���� ���� �ڿ����� ���Ѵ�.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int ArrayLength;                      // ���� S�� ����
int Input[20];                        // ���� S
bool visited[2000001];                // ���յ� ���� �湮 ����
bool ArrayVisited[20];                // ���� S�� �� ����� �湮 ����

void Bruteforce(int Start, int Sum, int Length)
{
    // ������ ���̸�ŭ ��� ����ٸ�, �Լ� ����
    if (Length >= ArrayLength)
        return;

    // �������������� '������ ����'��ŭ ��Ҹ� �����ϰ�,
    // �湮 ǥ�ø� �Ѵ�.
    for (int i = Start; i < ArrayLength; i++)
    {
        // ���� �湮���� �ʴ� ���̶�� �湮�Ѵ�.
        if (!ArrayVisited[i])
        {
            ArrayVisited[i] = true;
            visited[Sum + Input[i]] = true;
            Bruteforce(i, Sum + Input[i], Length + 1);
            ArrayVisited[i] = false;
        }
    }
}

int main()
{
    // ������ ���̿� ���� S �Է�
    cin >> ArrayLength;
    for (int i = 0; i < ArrayLength; i++)
        cin >> Input[i];

    // Bruteforce�� ��� ������ ���ϰ� �湮 ǥ�ø� �Ѵ�.
    Bruteforce(0, 0, 0);

    // ����� ���
    for (int i = 1; i < 2000001; i++)
        if (!visited[i])
        {
            cout << i;
            break;
        }

    return 0;
}