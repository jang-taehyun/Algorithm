/*
Problem : n개의 숫자와 (n-1)개의 연산자가 주어졌을 때, 주어진 숫자의 순서를 바꾸지 않고 만들 수 있는 수식의 최대값과 최솟값을 구해라.
Input : n개의 숫자, (n-1)개의 연산자
Output : 수식의 최대값, 최소값

Idea
- 항상 계산되는 수식이 -10^9 ~ 10^9 사이이므로 long long형으로 자료형을 설정
- 각 연산자 현재까지 사용된 횟수를 나타내는 UsingCount를 통해 각 연산자가 사용된 횟수를 표시
- DFS 방식을 통해 수식을 완성하여 최대값과 최소값을 구한다.
*/
#include <iostream>
#define MAX 9999999999
#define MIN -9999999999
using namespace std;

int InputNumberCount;               // 입력된 숫자들의 개수
long long InputNumber[11];          // 입력된 숫자들

int AbleUsingCount[4];              // 각 연산자들을 사용할 수 있는 횟수
                                    // 0 : +, 1 : -, 2 : *, 3 : /
int UsingCount[4];                  // 각 연산자들이 현재까지 사용된 횟수
int Operation[10];                  // 현재까지 선택된 연산자

long long MaximumNumber = MIN;        // 현재까지 계산된 수식 중 최대값
long long MinimumNumber = MAX;        // 현재까지 계산된 수식 중 최솟값

void DFS(int Length)
{
    // 만약 수식이 완성되었다면, 수식을 계산하고 최소값과 최대값 update
    if (Length >= InputNumberCount - 1)
    {
        long long tmp = InputNumber[0];

        for (int i = 0; i < Length; i++)
        {
            switch (Operation[i])
            {
            case 0:
            {
                tmp = (tmp + InputNumber[i + 1]);
            }
            break;
            case 1:
            {
                tmp = (tmp - InputNumber[i + 1]);
            }
            break;
            case 2:
            {
                tmp = (tmp * InputNumber[i + 1]);
            }
            break;
            case 3:
            {
                // 계산된 수식이 음수일 때
                if (tmp < 0)
                {
                    // 모두 양수로 만들어 주고
                    tmp *= (long long)(-1);

                    // 수식을 계산한 후, -1를 곱한다.
                    tmp = (tmp / InputNumber[i + 1]);
                    tmp *= (long long)(-1);
                }
                else
                    tmp = (tmp / InputNumber[i + 1]);
            }
            break;
            }
        }

        if (tmp > MaximumNumber)
            MaximumNumber = tmp;
        if (tmp < MinimumNumber)
            MinimumNumber = tmp;

        return;
    }

    // 연산자들을 고른다.
    for (int i = 0; i < 4; i++)
    {
        if (UsingCount[i] < AbleUsingCount[i])
        {
            UsingCount[i]++;
            Operation[Length] = i;
            DFS(Length + 1);
            UsingCount[i]--;
        }
    }
}

int main()
{
    // 입력될 숫자의 개수와 숫자를 입력받고, 사용할 수 있는 연산자의 개수를 입력받는다.
    cin >> InputNumberCount;
    for (int i = 0; i < InputNumberCount; i++)
        cin >> InputNumber[i];
    for (int i = 0; i < 4; i++)
        cin >> AbleUsingCount[i];

    // DFS 방식을 통해 수식을 완성하고 최대값과 최솟값을 구한다.
    DFS(0);

    // 결과값 출력
    cout << MaximumNumber << '\n' << MinimumNumber;

    return 0;
}