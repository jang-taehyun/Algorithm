/*
problem : n개의 element를 가진 수열 array에서 중복을 허락하지 않고 m개를 고를 때 non-decreasing order로 sort된 수열을 모두 출력해라.
input : 수열 array, 자연수 m
output : 수열 array에서 중복을 허락하지 않고 m개를 뽑아 non-decreasing order로 sort된 수열

idea : 수열 array를 non-decreasing order로 sort한 후, backtracking을 이용해 index 0번째부터 시작하여 DFS 방식으로 탐색한다.
- non-promising : 직전에 만든 수열과 현재 만든 수열이 같을 때
  -> 같은 level에서 전에 탐색했던 node와 현재 탐색한 node가 같은 경우
*/
#include <iostream>
#include <algorithm>
using namespace std;

int input[8];      // n개의 element를 가진 수열 input == array
int length;        // 수열 array의 길이 length == n
int choose;        // 고를 element의 개수 choose == m
int output[8];     // 수열 array에서 m개를 골라 만든 수열 output

void DFS(int currentCount, int startIndex)
{
    // m개를 모두 골랐다면, 수열 output 출력 후 탐색 종료
    if (choose == currentCount)
    {
        for (int i = 0; i < choose; i++)
            cout << output[i] << ' ';
        cout << '\n';

        return;
    }

    // 같은 level에서 전에 탐색했던 node인 lastChooseNode
    int lastChooseNode = 0;

    // startIndex부터 시작하여 DFS 방식으로 탐색해 m개를 고른다.
    for (int i = startIndex; i < length; i++)
    {
        // non-promising 조건 : 같은 level에서 전에 탐색했던 node와 현재 탐색한 node가 같은 경우
        if (lastChooseNode != input[i])
        {
            // lastChooseNode를 현재 node로 설정
            lastChooseNode = input[i];

            // 현재 node를 수열 output에 넣고, 다음 level 탐색
            output[currentCount] = input[i];
            DFS(currentCount + 1, i + 1);
        }
    }
}

int main()
{
    // input 입력
    cin >> length >> choose;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    // 수열 input을 non-decreasing order로 sort
    sort(input, input + length);

    // DFS 방식으로 m개를 골라 수열 output 만들기
    DFS(0, 0);

    return 0;
}