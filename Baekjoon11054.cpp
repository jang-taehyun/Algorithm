/*
problem : 수열 S의 가장 긴 바이토닉 수열의 길이를 구해라
input : 수열 S의 길이 n, 수열 s의 요소 value
output : 수열 S의 가장 긴 바이토닉 수열의 길이

idea
- 수열 S의 1번째 요소부터 시작해 n번째 요소까지 가장 긴 증가하는 부분 수열을 구한다.
- 수열 S의 n번째 요소부터 시작해 1번째 요소까지 가장 긴 감소하는 부분 수열을 구한다.
- 각 요소를 더한 후 1을 뺸다.
- 관계식
  - dp_increase[i] : i번째 요소를 맨 끝에 포함하면서, 0부터 i번째 요소들만을 골라, 만들 수 있는 가장 긴 증가하는 부분 수열
  - dp_decrease[i] : i번째 요소를 맨 처음에 포함하면서, i부터 (n-1)번째 요소들만을 골라, 만들 수 있는 가장 긴 감소하는 부분 수열
  - dp_bitonic[i] : i번째 요소를 기준으로 만들 수 있는 가장 긴 바이토닉 부분 수열의 길이
  - dp_bitonic[i] = dp_increase[i] + dp_decrease[i] - 1
- dp_bitonic에 저장된 값 중 가장 큰 것을 출력한다.
*/
#include <iostream>
using namespace std;

int Max(int x, int y) { return x > y ? x : y; }

int main()
{
    // 수열의 길이 n
    int n = 0;
    // 수열의 요소 value
    int value[1000];
    // 가장 긴 증가하는 부분 수열 dp_increase
    int dp_increase[1000];
    // 가장 긴 감소하는 부분 수열 dp_decrease
    int dp_decrease[1000];
    // 가장 긴 바이토닉 부분 수열 dp_bitonic
    int dp_bitonic[1000];
    // dp_bitonic에 저장된 요소 중 가장 큰 값 res
    int res = 0;

    // 수열의 길이 n과 수열의 요소 value 입력
    cin >> n;
    for (int index = 0; index < n; index++)
        cin >> value[index];

    // dp_increase, dp_decrease, dp_bitonic을 모두 1로 초기화
    for (int index = 0; index < n; index++)
    {
        dp_increase[index] = 1;
        dp_decrease[index] = 1;
        dp_bitonic[index] = 1;
    }

    // 0번째 요소부터 (n-1)번째 요소까지 순서대로 가장 긴 증가하는 부분 수열 구하기
    for (int currentIndex = 0; currentIndex < n; currentIndex++)
        for (int prevIndex = 0; prevIndex < currentIndex; prevIndex++)
            if (value[currentIndex] > value[prevIndex])
                dp_increase[currentIndex] = Max(dp_increase[currentIndex], dp_increase[prevIndex] + 1);

    // (n-1)번째 요소부터 0번째 요소까지 순서대로 가장 긴 감소하는 부분 수열 구하기
    for (int currentIndex = n - 1; currentIndex > -1; currentIndex--)
        for (int prevIndex = n - 1; prevIndex > currentIndex; prevIndex--)
            if (value[currentIndex] > value[prevIndex])
                dp_decrease[currentIndex] = Max(dp_decrease[currentIndex], dp_decrease[prevIndex] + 1);

    // 0번째 요소부터 (n-1)번째 요소까지 가장 긴 bitonic 부분 수열 계산
    for (int index = 0; index < n; index++)
    {
        dp_bitonic[index] = dp_increase[index] + dp_decrease[index] - 1;

        if (res < dp_bitonic[index])
            res = dp_bitonic[index];
    }

    // 결과 출력
    cout << res;

    return 0;
}

/*
한 번에 풀지 못한 이유
- 문제를 분해하지 않고 해결하려고 함
  -> 문제를 '가장 긴 증가하는 부분 수열의 길이 + 가장 긴 감소하는 부분 수열의 길이'로 분해
- 이전에 푼 문제들을 합쳐서 응용하는 문제
  -> 이전에 비슷한 문제를 풀어봤는지 생각해보기
*/