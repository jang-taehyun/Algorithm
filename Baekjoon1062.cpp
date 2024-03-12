/*
problem : k개의 알파벳만 알 수 있고 n개의 단어가 주어질 때, k개의 알파벳만을 이용해 읽을 수 있는 단어의 최대 개수를 구해라.
input : 알 수 있는 알파벳의 개수 k, n개의 단어
output : k개의 알파벳을 이용해, n개의 단어 중 읽을 수 있는 단어의 최대 개수

idea
- n개의 단어에서 "anta"와 "tica"를 제외하고, 4개의 알파벳(a, n, t, i)를 읽을 수 있다고 가정한다.
- 만약 k가 5보다 작으면 0을 출력
- DFS 방식을 이용해 (k-5)개 만큼 알파벳을 고르고, 읽을 수 있는 단어의 최대 개수를 구한다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ESSENTIAL 5
using namespace std;

vector<string> InputWord;            // 입력된 단어
int WordCount, KnownAlphabet;        // 단어의 개수, 알고 있는 알파벳의 개수
bool IsKnown[26];                    // 알파벳을 알고 있는지 여부
int MaximumReadWordCount = 0;          // 읽을 수 있는 단어의 최대 개수

void DFS(int start, int count)
{
    // 만약 알파벳을 모두 골랐다면, 입력된 단어들을 검사해 읽을 수 있는 단어의 최대 개수를 update
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

    // (k-5)개의 알파벳 중 하나를 고른다.
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

    // 단어의 개수, 읽을 수 있는 알파벳의 개수, 단어들을 입력
    cin >> WordCount >> KnownAlphabet;
    for (int i = 0; i < WordCount; i++)
    {
        cin >> input;

        input.erase(0, 4);
        input.erase(input.length() - 4, input.length());
        InputWord.push_back(input);
    }

    // 읽을 수 있는 알파벳의 개수가 5개 이하라면 0을 출력
    if (KnownAlphabet < 5)
    {
        cout << MaximumReadWordCount;
        return 0;
    }

    // a, n, t, i, c를 알고 있다고 가정하고, (k-5)개의 알파벳을 고른다.
    IsKnown['a' - 'a'] = true;
    IsKnown['n' - 'a'] = true;
    IsKnown['t' - 'a'] = true;
    IsKnown['i' - 'a'] = true;
    IsKnown['c' - 'a'] = true;
    DFS(1, 0);

    // 결과값 출력
    cout << MaximumReadWordCount;

    return 0;
}