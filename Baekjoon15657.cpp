/*
problem : n개의 element를 가진 수열 array에서 중복을 허락하여 m개를 골라 non-decreasing order로 정렬된 수열을 모두 출력해라.
input : 수열 array, 자연수 m
output : 중복을 허락하여 m개를 골라 non-decreasing order로 정렬된 수열

idea : 수열 array을 non-decreasing order로 정렬한 후, DFS 방식으로 탐색하면서 m개를 골라 수열을 만든다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int input[8];    // n개의 element를 가진 수열 input == array
int length;      // 수열 array의 길이 length == n
int choose;      // 고를 element의 개수 choose == m
int output[8];   // m개의 element를 골라 만들어진 수열 output

void DFS(int currentCount, int startNode)
{
    // m개를 모두 골랐다면 수열 출력 후 function 종료
    if (currentCount == choose)
    {
        for (int i = 0; i < choose; i++)
            cout << output[i] << ' ';
        cout << '\n';

        return;
    }

    // startNode의 모든 child node를 DFS 방식으로 탐색하면서 m개를 고른다.
    // -> 이때 child node는 현재 index부터 (n-1)번째 index까지이다.
    for (int i = startNode; i < length; i++)
    {
        output[currentCount] = input[i];
        DFS(currentCount + 1, i);
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

    // index 0번째부터 출발해 DFS 방식으로 탐색하여 m개를 고른다.
    DFS(0, 0);

    return 0;
}