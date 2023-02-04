/*
problem : n개의 element를 가진 수열 array에서 중복을 허용하여 m개를 골라 만들어지는 non-decreasing order로 정렬된 수열들을 중복없이 모두 출력하라.
input : 수열 array, 고를 element의 개수 m
output : m개를 중복을 허용하여 만든 non-decreasing order로 정렬된 수열들

idea : 수열 array를 non-decreasing order로 정렬한 후 DFS 방식으로 탐색하여 m개를 고른다.
- non-promising 조건 : 이전에 만들어진 수열과 현재 만들어진 수열이 같은 경우
  -> 같은 level에서 직전에 고른 숫자와 현재 고른 숫자가 같을 때
*/
#include <iostream>
#include <algorithm>
using namespace std;

int input[8];    // n개의 element를 가진 수열 input == array
int length;      // 수열 array의 길이 length == n
int choose;      // 고를 element의 개수 choose == m
int output[8];   // m개를 골라 만든 수열 output

void DFS(int currentCount, int startIndex)
{
    // m개를 모두 골랐다면, 수열 output 출력 후 탐색 종료
    if (currentCount == choose)
    {
        for (int i = 0; i < choose; i++)
            cout << output[i] << ' ';
        cout << '\n';

        return;
    }

    // 같은 level에서 직전에 고른 숫자 lastChooseNumber
    int lastChooseNumber = 0;

    // 수열 array를 DFS 방식으로 탐색하면서 m개를 고른다.
    for (int i = startIndex; i < length; i++)
    {
        // non-promising 조건 : 같은 level에서 직전에 고른 숫자와 현재 고른 숫자가 같은 경우
        if (lastChooseNumber != input[i])
        {
            // lastChooseNumber를 현재 숫자로 업데이트
            lastChooseNumber = input[i];

            // 현재 숫자를 output에 넣고 DFS 방식으로 수열 array를 탐색
            output[currentCount] = input[i];
            DFS(currentCount + 1, i);
        }
    }
}

int main()
{
    // input 입력
    cin >> length >> choose;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    // 수열 array를 non-decreasing order로 sort
    sort(input, input + length);

    // 수열 array를 DFS 방식으로 탐색하면서 m개를 골라 수열 output 만들기
    DFS(0, 0);

    return 0;
}