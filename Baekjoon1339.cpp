/*
Problem : 각 알파벳에 0부터 9까지의 숫자를 할당하고 단어들이 주어졌을 때, 단어들의 최대 합을 구해라.
Input : 단어의 개수, 단어
Output : 단어들의 최대 합

Idea
- 입력받은 단어에서 각 알파벳마다 자리수를 매긴다.
  ex) ABC라면 A=100, B=10, C=1
- 각 알파벳마다 할당된 자리수를 모두 더한다.
- 내림차순으로 정렬한 뒤, 9부터 구해진 수를 곱하여 계속 더한다.
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int AlphabetNumber[26];       // 각 알파벳의 위치를 통해 할당된 자리수들의 합

bool IsMinimum(int a, int b) { return a > b; }

int main()
{
    int WordCount;                // 전체 단어의 개수
    string input;                 // 입력된 단어
    int Result = 0;                 // 결과값

    int Index;                    // 단어의 index
    int Location;                 // 각 알파벳의 자리수, 곱하는 수

    // 단어의 개수와 단어들 입력
    cin >> WordCount;
    for (int i = 0; i < WordCount; i++)
    {
        cin >> input;

        // 입력된 단어들의 자리수를 통해 자리수를 할당하고 모두 더한다.
        Location = 1;
        for (int j = input.length() - 1; j >= 0; j--)
        {
            Index = input[j] - 'A';
            AlphabetNumber[Index] += Location;

            // 자리수를 *10한다.
            Location *= 10;
        }
    }

    // 구해진 수들을 내림차순으로 정렬
    sort(AlphabetNumber, AlphabetNumber + 26, IsMinimum);

    // 9부터 시작해 구해진 숫자를 곱한다.
    // 이후 계속 누적해 더한다.
    Location = 9;
    for (int i = 0; i < 26; i++)
    {
        // 만약 숫자 0이 나왔다면 모두 더한 것이므로 loop 종료
        if (!AlphabetNumber[i])
            break;

        Result += (AlphabetNumber[i] * Location);

        Location--;
    }

    // 결과값 출력
    cout << Result;

    return 0;
}