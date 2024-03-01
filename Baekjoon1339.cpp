/*
Problem : �� ���ĺ��� 0���� 9������ ���ڸ� �Ҵ��ϰ� �ܾ���� �־����� ��, �ܾ���� �ִ� ���� ���ض�.
Input : �ܾ��� ����, �ܾ�
Output : �ܾ���� �ִ� ��

Idea
- �Է¹��� �ܾ�� �� ���ĺ����� �ڸ����� �ű��.
  ex) ABC��� A=100, B=10, C=1
- �� ���ĺ����� �Ҵ�� �ڸ����� ��� ���Ѵ�.
- ������������ ������ ��, 9���� ������ ���� ���Ͽ� ��� ���Ѵ�.
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int AlphabetNumber[26];       // �� ���ĺ��� ��ġ�� ���� �Ҵ�� �ڸ������� ��

bool IsMinimum(int a, int b) { return a > b; }

int main()
{
    int WordCount;                // ��ü �ܾ��� ����
    string input;                 // �Էµ� �ܾ�
    int Result = 0;                 // �����

    int Index;                    // �ܾ��� index
    int Location;                 // �� ���ĺ��� �ڸ���, ���ϴ� ��

    // �ܾ��� ������ �ܾ�� �Է�
    cin >> WordCount;
    for (int i = 0; i < WordCount; i++)
    {
        cin >> input;

        // �Էµ� �ܾ���� �ڸ����� ���� �ڸ����� �Ҵ��ϰ� ��� ���Ѵ�.
        Location = 1;
        for (int j = input.length() - 1; j >= 0; j--)
        {
            Index = input[j] - 'A';
            AlphabetNumber[Index] += Location;

            // �ڸ����� *10�Ѵ�.
            Location *= 10;
        }
    }

    // ������ ������ ������������ ����
    sort(AlphabetNumber, AlphabetNumber + 26, IsMinimum);

    // 9���� ������ ������ ���ڸ� ���Ѵ�.
    // ���� ��� ������ ���Ѵ�.
    Location = 9;
    for (int i = 0; i < 26; i++)
    {
        // ���� ���� 0�� ���Դٸ� ��� ���� ���̹Ƿ� loop ����
        if (!AlphabetNumber[i])
            break;

        Result += (AlphabetNumber[i] * Location);

        Location--;
    }

    // ����� ���
    cout << Result;

    return 0;
}