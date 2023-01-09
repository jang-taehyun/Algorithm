/*
problem : 수열 A의 가장 긴 감소하는 부분 수열의 길이를 구해라
input : 수열의 크기 n(1<=n<=1000), 수열 A를 이루고 있는 요소 value(1<=value<=1000)
output : 가장 긴 감소하는 부분 수열의 길이 출력

idea
- 수열 A가 {10, 30, 10, 20, 10}라고 가정하자.
  이때 각 요소들마다 가장 작은 감소하는 부분 수열은 자기 자신만 포함될 때이다.
  첫번째 요소부터 마지막 요소까지 순차적으로 탐색하면서 가장 긴 감소하는 부분 수열의 길이를 구한다.
- 1번째 요소를 포함하면서 가장 긴 감소하는 부분 수열은 자기 자신만 포함될 때이다.
  10
- 2번째 요소를 포함하면서 가장 긴 감소하는 부분 수열은 자기 자신만 포함될 때이다.
  30
- 3번째 요소를 포함하면서 가장 긴 감소하는 부분 수열은 자기 자신만 포함될 때이다.
  10
- 4번째 요소를 포함하면서 가장 긴 감소하는 부분 수열은 다음과 같다.
  - 1번째 요소를 탐색했을 때 나온 결과에 4번째 요소 추가 : 불가능
  - 2번째 요소를 탐색했을 때 나온 결과에 4번째 요소 추가 : 30, 20
  - 3번째 요소를 탐색했을 때 나온 결과에 4번째 요소 추가 : 불가능
- 5번째 요소를 포함하면서 가장 긴 감소하는 부분 수열은 다음과 같다.
  - 1번째 요소를 탐색했을 때 나온 결과에 4번째 요소 추가 : 불가능
  - 2번째 요소를 탐색했을 때 나온 결과에 4번째 요소 추가 : 30, 10
  - 3번째 요소를 탐색했을 때 나온 결과에 4번째 요소 추가 : 불가능
  - 4번째 요소를 탐색했을 때 나온 결과에 4번째 요소 추가 : 30, 20, 10
- 이를 통해 관계식 도출
  - dp[i] : i번째 요소를 포함할 때 나오는 가장 긴 감소하는 부분 수열의 길이
  - dp[i] = max(dp[i], dp[j]+1) (j : 이전에 계산했던 요소)
  - 여기에서 value[i] > value[j]여야 감소하는 부분 수열을 만들 수 있다.
- 1번째 요소부터 n번째 요소까지 관계식을 이용해 가장 긴 감소하는 부분 수열의 길이를 구하고,
  그 중 가장 큰 값을 출력한다.
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
    // 각 요소를 포함할 때 나오는 가장 긴 감소하는 부분 수열의 길이 dp
    int dp[1000];
    // dp에 저장된 요소 중 가장 큰 값 res
    int res = 0;

    // 수열의 길이 n과 수열의 요소 value 입력 & dp 초기화(dp의 초기값 : 자기 자신만 포함했을 때 나오는 경우의 길이)
    cin >> n;
    for (int index = 0; index < n; index++)
    {
        cin >> value[index];
        dp[index] = 1;
    }

    // 1부터 n까지 관계식을 이용해 dp 계산
    for (int currentIndex = 0; currentIndex < n; currentIndex++)
        for (int prevIndex = 0; prevIndex < currentIndex; prevIndex++)
            if (value[currentIndex] < value[prevIndex])
                dp[currentIndex] = Max(dp[currentIndex], dp[prevIndex] + 1);

    // dp에 저장된 값 중 가장 큰 값을 찾아 출력
    for (int index = 0; index < n; index++)
        if (res < dp[index])
            res = dp[index];
    cout << res;

    return 0;
}

/*
한 번에 맞추지 못한 이유
1) memset 함수에 대한 이해 부족
   -> 1로 초기화할 때와 0으로 초기화할 떄는 다르다!
2) 코드의 흐름을 무시한 채 dp 초기화
   -> n의 입력을 받기 전 n을 이용해 dp를 초기화함
*/