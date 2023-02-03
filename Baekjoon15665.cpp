/*
problem : n개의 element를 가진 수열 array에서 중복을 허용하여 m개를 고를 때 나온 수열을 중복없이 모두 출력해라.
input : 수열 array, 자연수 m
output : 중복을 허용하여 m개를 고를 때 만들어지는 수열들

idea : 수열 array를 non-decreasing order로 sort한 후 DFS 방식으로 탐색하여 m개를 고른다.
- non-promising : 중복된 수열이 만들어 질 때
  -> 같은 level에서 직전에 골랐던 숫자와 현재 고른 숫자가 같을 때
*/
#include <iostream>
#include <algorithm>
using namespace std;

int input[7];    // n개의 element를 가진 수열 input == array
int length;      // 수열 array의 길이 length == n
int choose;      // 고를 element의 개수 choose == m
int output[7];   // m개를 골라 만들어진 수열 output

void DFS(int currentCount)
{
    // m개를 모두 골랐다면, 수열 출력 후 탐색 종료
    if (currentCount == choose)
    {
        for (int i = 0; i < choose; i++)
            cout << output[i] << ' ';
        cout << '\n';

        return;
    }

    // 같은 level에서 직전에 골랐던 숫자 lastChooseNumber
    int lastChooseNumber = 0;

    // 수열 array에서 DFS 방식으로 element를 m개 고른다.
    for (int i = 0; i < length; i++)
    {
        // non-promising 조건 : 같은 level에서 직전에 골랐던 숫자와 현재 고른 숫자가 같을 때
        if (input[i] != lastChooseNumber)
        {
            // lastChooseNumber를 현재 숫자로 update
            lastChooseNumber = input[i];

            // 현재 숫자를 output에 넣고, 다음 level로 넘어가 탐색
            output[currentCount] = input[i];
            DFS(currentCount + 1);
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

    // 수열 array를 DFS 방식으로 탐색해 m개를 골라 수열 만들기
    DFS(0);

    return 0;
}