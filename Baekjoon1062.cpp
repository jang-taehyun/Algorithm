/*
problem : k���� ���ĺ��� �� �� �ְ� n���� �ܾ �־��� ��, k���� ���ĺ����� �̿��� ���� �� �ִ� �ܾ��� �ִ� ������ ���ض�.
input : �� �� �ִ� ���ĺ��� ���� k, n���� �ܾ�
output : k���� ���ĺ��� �̿���, n���� �ܾ� �� ���� �� �ִ� �ܾ��� �ִ� ����

idea
- n���� �ܾ�� "anta"�� "tica"�� �����ϰ�, 4���� ���ĺ�(a, n, t, i)�� ���� �� �ִٰ� �����Ѵ�.
- ���� k�� 5���� ������ 0�� ���
- DFS ����� �̿��� (k-5)�� ��ŭ ���ĺ��� ����, ���� �� �ִ� �ܾ��� �ִ� ������ ���Ѵ�.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ESSENTIAL 5
using namespace std;

vector<string> InputWord;            // �Էµ� �ܾ�
int WordCount, KnownAlphabet;        // �ܾ��� ����, �˰� �ִ� ���ĺ��� ����
bool IsKnown[26];                    // ���ĺ��� �˰� �ִ��� ����
int MaximumReadWordCount = 0;          // ���� �� �ִ� �ܾ��� �ִ� ����

void DFS(int start, int count)
{
    // ���� ���ĺ��� ��� ����ٸ�, �Էµ� �ܾ���� �˻��� ���� �� �ִ� �ܾ��� �ִ� ������ update
    if (count >= KnownAlphabet - ESSENTIAL)
    {
        bool IsRead;
        int CurrentReadWordCount = 0;
        for (int i = 0; i < WordCount; i++)
        {
            IsRead = true;
            for (int j = 0; j < InputWord[i].length(); j++)
                if (!IsKnown[InputWord[i][j] - 'a'])
                {
                    IsRead = false;
                    break;
                }

            if (IsRead)
                CurrentReadWordCount++;
        }

        MaximumReadWordCount = max(MaximumReadWordCount, CurrentReadWordCount);

        return;
    }

    // (k-5)���� ���ĺ� �� �ϳ��� ����.
    for (int i = start; i < 26; i++)
    {
        if (!IsKnown[i])
        {
            IsKnown[i] = true;
            DFS(i + 1, count + 1);
            IsKnown[i] = false;
        }
    }
}

int main()
{
    string input;

    // �ܾ��� ����, ���� �� �ִ� ���ĺ��� ����, �ܾ���� �Է�
    cin >> WordCount >> KnownAlphabet;
    for (int i = 0; i < WordCount; i++)
    {
        cin >> input;

        input.erase(0, 4);
        input.erase(input.length() - 4, input.length());
        InputWord.push_back(input);
    }

    // ���� �� �ִ� ���ĺ��� ������ 5�� ���϶�� 0�� ���
    if (KnownAlphabet < 5)
    {
        cout << MaximumReadWordCount;
        return 0;
    }

    // a, n, t, i, c�� �˰� �ִٰ� �����ϰ�, (k-5)���� ���ĺ��� ����.
    IsKnown['a' - 'a'] = true;
    IsKnown['n' - 'a'] = true;
    IsKnown['t' - 'a'] = true;
    IsKnown['i' - 'a'] = true;
    IsKnown['c' - 'a'] = true;
    DFS(1, 0);

    // ����� ���
    cout << MaximumReadWordCount;

    return 0;
}