/*
problem : n의 길이를 가지는 수열 S가 존재하고, k번째 요소를 선택했을 때 k번째 요소를 제거하고 (k-1)번째 요소와 (k+1)번째 요소를 선택해 곱하고 누적합에 더한다.
이때 나올 수 있는 누적합의 최대값을 구해라.
input : 수열 S
output : 누적합의 최대값

idea
- 2번째 요소부터 (n-1)번째 요소까지 DFS 방식을 사용해 (n-2)번 탐색한다.
- 탐색을 완료하면 구해진 누적합을 이전까지 구한 최대값과 비교해 큰 값으로 update한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool removed[10];                // 각 요소의 제거 여부
int InputArray[10];              // 입력받은 수열 S
int ArrayLength = 0;               // 수열 S의 길이
int Result = 0;                    // 누적합의 최대값

void DFS(int length, int sum)
{
    // 만약 1번째 요소와 n번째 요소를 제외하고 모두 제거했다면
    // 이전까지 구한 최대값과 비교해 큰 값으로 update한다.
    if (length >= ArrayLength - 2)
    {
        Result = max(Result, sum);

        return;
    }

    // 아직 제거되지 않는 요소 중 하나를 골라 제거한다.
    for (int i = 1; i < ArrayLength - 1; i++)
    {
        if (!removed[i])
        {
            removed[i] = true;

            // 왼쪽, 오른쪽 operand를 구한다.
            int LeftOperand, RightOperand;
            for (int j = i - 1; j >= 0; j--)
            {
                if (!removed[j])
                {
                    LeftOperand = InputArray[j];
                    break;
                }
            }
            for (int j = i + 1; j < ArrayLength; j++)
            {
                if (!removed[j])
                {
                    RightOperand = InputArray[j];
                    break;
                }
            }

            // 구한 operand를 곱하고 누적합에 더해
            // 다음 요소를 탐색한다.
            DFS(length + 1, sum + (LeftOperand * RightOperand));

            removed[i] = false;
        }
    }
}

int main()
{
    // 수열 S의 길이와 각 요소을 입력
    cin >> ArrayLength;
    for (int i = 0; i < ArrayLength; i++)
        cin >> InputArray[i];

    // DFS 방식으로 탐색해 누적합의 최대값을 찾는다.
    DFS(0, 0);

    // 결과값 출력
    cout << Result;

    return 0;
}