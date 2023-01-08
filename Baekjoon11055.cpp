/*
problem : 수열 A에서, 그 수열의 증가 부분 수열 중 합이 가장 큰 것을 구해라
input : 수열 A의 크기 n, 수열 A의 요소 value(1 <= n <= 1000, 1 <= value <= 1000)
output : 증가 부분 수열의 합 중 가장 큰 것

idea
- 수열 A가, {1, 100, 2, 50}로 주어졌다고 가정하고, 각 요소를 포함하는 증가 부분 수열은 다음과 같다.
  1번째 요소를 포함하는 증가 부분 수열 : 1
  2번째 요소를 포함하는 증가 부분 수열 : 1, 100
  3번째 요소를 포함하는 증가 부분 수열 : 1, 2
  4번째 요소를 포함하는 증가 부분 수열 : 1, 2, 50
- 여기에서 '각 요소를 포함하는 부분 수열 중 가장 작은 길이'는 다음과 같다.
  1번째 요소를 포함하는 증가 부분 수열 : 1
  2번째 요소를 포함하는 증가 부분 수열 : 100
  3번째 요소를 포함하는 증가 부분 수열 : 2
  4번째 요소를 포함하는 증가 부분 수열 : 50
- 만약 dp[i]를 'i번째 요소를 포함하는 증가 부분 수열의 합 중 최대값'이라고 하자.
  그렇다면, dp[i]의 초기값은 '각 요소를 포함하는 부분 수열 중 가장 작은 길이'이다.
- dp[i]는 1부터 (i-1)번째까지 요소 중 i번째 요소보다 작으면서(이를 j라고 하자.),
  (dp[j] + value[i])가 dp[i]보다 커야 한다.
- 관계식 도출
  - dp[i] = max(dp[i], dp[j] + value[i]);
- 수열의 끝까지 탐색한 후, dp에 저장된 값 중 최대값을 찾아 출력
*/

#include <iostream>
#include <cstring>
using namespace std;

int Max(int x, int y) { return x > y ? x : y; }

int main()
{
    // 수열의 길이 n
    int n = 0;
    // 수열의 요소 value
    int value[1000];
    // 관계식을 이용해 최대값을 저장할 dp
    int dp[1000];
    // 현재까지 계산한 값 중 최대값을 저장할 max
    int max = 0;

    // value와 dp 초기화
    memset(value, 0, sizeof(value));
    memset(dp, 0, sizeof(dp));

    // 수열의 길이 n과 수열의 요소 value 입력 & dp 초기화
    cin >> n;
    for (int index = 0; index < n; index++)
    {
        cin >> value[index];
        dp[index] = value[index];
    }

    // 0부터 (n-1)까지 관계식을 이용해 최대값 계산
    for (int currentIndex = 0; currentIndex < n; currentIndex++)
        for (int prevIndex = 0; prevIndex < currentIndex; prevIndex++)
            if (value[currentIndex] > value[prevIndex])
                dp[currentIndex] = Max(dp[currentIndex], dp[prevIndex] + value[currentIndex]);

    // 최대값을 찾아 결과 출력
    for (int index = 0; index < n; index++)
        max = Max(max, dp[index]);
    cout << max;


    return 0;
}

/*
한 번에 풀지 못한 이유
- 바로 직전에 계산된 값만을 이용
- 예시를 먼저 푼 후, 관계식을 도출 & 관계식을 복잡하게 도출함
  -> dp의 의미를 먼저 정한 후, 관계식을 도출하는 방법도 있다.
  -> 경우를 나눠서 생각해, 계산해야 할 연산량도 많아지고 조건도 많아짐
*/