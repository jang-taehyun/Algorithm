/*
problem : n개의 element를 가진 수열 array에서 중복없이 m개를 뽑아 increasing order로 sort된 수열을 중복없이 모두 출력해라.
input : 수열 array, 자연수 m
output : 수열 array에서 중복없이 m개를 뽑아 increasing order로 sort된 수열을 중복없이 모두 출력

idea : 수열 array를 increasing order로 sort한 후 index 0번째부터 시작하여 DFS 방식으로 m개를 뽑는다.
- Backtracking의 non-promisin 조건
  1) 현재 node를 이미 뽑았다면, 다시 뽑지 않는다.
  2) 직전에 뽑았던 숫자와 현재 뽑은 숫자가 같으면, 뽑지 않는다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int input[8];      // n개의 element를 가진 수열 input == array
int length;        // 수열 array의 길이 length == n
int choose;        // 뽑을 숫자의 개수 choose == m
bool isVisited[8]; // 현재 index 방문 여부 isVisited
int output[8];     // m개를 뽑아 만든 수열 output

void DFS(int currentCount)
{
    // m개를 모두 골랐다면 수열 output을 출력 후 function 종료
    if (currentCount == choose)
    {
        for (int i = 0; i < choose; i++)
            cout << output[i] << ' ';
        cout << '\n';

        return;
    }

    // 직전에 뽑았던 숫자 lastChooseNumber
    int lastChooseNumber = 0;

    // 현재 node의 child node를 모두 탐색
    for (int i = 0; i < length; i++)
    {
        // non-promising : 현재 index를 방문하였다 or 직전에 뽑았던 숫자와 현재 뽑았던 숫자가 같다.
        if (!isVisited[i] && lastChooseNumber != input[i])
        {
            // 방문 표시 & lastChooseNumber를 i번째 숫자로 지정
            isVisited[i] = true;
            lastChooseNumber = input[i];

            // output에 i번째 숫자 저장
            output[currentCount] = input[i];

            // child node 탐색
            DFS(currentCount + 1);

            // 방문 표시 해제
            isVisited[i] = false;
        }
    }
}

int main()
{
    // input 입력
    cin >> length >> choose;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    // 수열 input을 increasing order로 sort
    sort(input, input + length);

    // DFS 방식으로 탐색하여 m개를 고른다.
    DFS(0);

    return 0;
}