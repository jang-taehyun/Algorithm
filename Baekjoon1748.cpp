/*
problem : 1���� n������ ���ڸ� �̾�ٿ� ������� ����� �� �ڸ� ������ ���ض�
input : �̾���� ������ ���� n
output : 1���� n������ ���ڸ� �̾�ٿ� ������� ����� �ڸ���

idea
- n�� 1~9���̿� �ִ� ���(n�� 1�ڸ��� ���) : 1*n
- n�� 10~99���̿� �ִ� ���(n�� 2�ڸ��� ���) : 1*9 + 2*(n-10+1)
- n�� 100~999���̿� �ִ� ���(n�� 3�ڸ��� ���) : 1*9 + 2*(99-10+1) + 3*(n-100+1)
- n�� k�ڸ��� ��� : 1*9 + 2*90 + 3*900 + ... + k(n-10^k+1)
- �̷��� ���踦 �̿��� ������ �ذ��Ѵ�.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // �̾���� ���� n
    int n = 0;
    // ������ ������ ���� first
    int first = 1;
    // ������ ������ ���� last
    int last = 9;
    // n�� ���� numberlength == k
    int numberlength = 0;
    // ���� Ž���ϰ� �ִ� ������ ���� length
    int length = 1;
    // ����� res
    int res = 0;

    // n �Է�
    cin >> n;

    // numberlength �ʱ�ȭ
    numberlength = to_string(n).length();

    // length-1 �ڸ����� �������� �ڸ��� ���
    for (length = 1; length < numberlength; length++)
    {
        res += (length * (last - first + 1));

        // first, last ������Ʈ
        first *= 10;
        last = last * 10 + 9;
    }

    // k �ڸ����� �������� �ڸ������� �ջ�
    res += (numberlength * (n - first + 1));

    // ����� ���
    cout << res;

    return 0;
}