/*
problem : 1���� n���� ���� �̿��� ������ ���� �� ���� ������ ������ ��, ���� array�� ���� ������ ���ض�. ���ٸ� -1�� ����ض�.
input : ������ ���� n, ���� array
output : ���� ������ �������� �� ���� array �������� ���� ����

idea
- �ڿ������� Ž���Ͽ� ���������� �����ϴ� ������ ã�´�.
  - �̶� ������ ù�κб��� �����ߴٸ� ���������� ��������� �����̹Ƿ� -1�� ����ϰ� ������.
- ���������� ù ����(index ��° ����)���� �տ� �ִ� ����(index-1 ��° ����)���� ó������ ū ���ڸ� ã�� �ڸ��� �ٲ��ش�.
- �����ڼ��� ù ���ں��� ������ ���ڱ��� �ڸ��� ��� �ٲ��ش�.
*/
#include <iostream>
using namespace std;

int length;               // ������ ���� length == n
int input[10000];         // input���� �־����� ���� input == array

void Swap(int i1, int i2)
{
    int temp = input[i1];
    input[i1] = input[i2];
    input[i2] = temp;
}

bool Next_Permutation()
{
    // ���������� ���� �κ� ã��
    int startIndex = length - 1;
    while (startIndex > 0 && input[startIndex - 1] >= input[startIndex])
        startIndex--;
    if (startIndex <= 0)
        return false;

    // ���������� ���ۺ��� �տ� �ִ� ���ں��� ó������ ū ���� ã�Ƽ� swap
    int Biggerindex = length - 1;
    while (input[startIndex - 1] >= input[Biggerindex])
        Biggerindex--;
    Swap(startIndex - 1, Biggerindex);

    // ���������� ���ۺ��� ������ �ڸ��� ��� �ٲ��ش�.
    int endIndex = length - 1;
    while (startIndex < endIndex)
        Swap(startIndex++, endIndex--);
    return true;
}

int main()
{
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    if (!Next_Permutation())
        cout << -1;
    else
        for (int i = 0; i < length; i++)
            cout << input[i] << ' ';

    return 0;
}