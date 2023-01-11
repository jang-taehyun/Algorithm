/*
problem : 수열 S에서 연속된 몇 개의 숫자를 선택해 구할 수 있는 최대 합을 구해라
input : 수열의 길이 n, 수열의 요소 value
output : 연속된 몇 개의 숫자를 선택해 구할 수 있는 최대 합

idea
- dp[i][k]를 'i번째 요소에서 k 경우를 선택했을 때 구할 수 있는 연속 합의 최대'이라고 하자.
  k=0 이면 특정 요소를 제거하지 않았을 때 구할 수 있는 연속 합의 최대, k=1 이면 특정 요소를 제거할 때 구할 수 있는 연속 합의 최대이다.
- 관계식은 다음과 같다.
  dp[i][0] = max(dp[i-1][0]+value[i], value[i]);
  dp[i][1] = max(dp[i-1][0], dp[i-1][1]+value[i]);
- 여기에서 특정 요소를 제거할 때 구할 수 있는 연속 합의 최대값은 다음과 같은 경우 중 큰 값을 선택한다.
  1) i번째 요소를 제거한 경우 : dp[i-1][0]
  2) i번째 이전에 요소를 제거한 경우 : dp[i-1][1] + value[i]
- dp에 존재하는 값 중 가장 큰 값을 찾아서 출력

*/
#include <iostream>
using namespace std;

int Max(int x, int y) { return x > y ? x : y; }

int main()
{
    // 수열의 길이 n
    int n = 0;
    // 수열의 요소 value
    int value[100000];
    // 관계식을 통해 계산된 연속 합의 최대값 dp
    int dp[100000][2];
    // dp에 저장된 값 중 가장 큰 값 res
    int res = 0;

    // 수열의 길이 n과 수열의 요소 value 입력 & 수열의 요소 중 가장 작은 값을 min에 저장
    cin >> n;
    for (int index = 0; index < n; index++)
        cin >> value[index];

    // 관계식을 이용해 각 요소를 탐색할 때 나오는 경우에서 최대값 저장
    dp[0][0] = value[0];
    dp[0][1] = value[0];
    for (int index = 1; index < n; index++)
    {
        dp[index][0] = Max(dp[index - 1][0] + value[index], value[index]);
        dp[index][1] = Max(dp[index - 1][0], dp[index - 1][1] + value[index]);
    }

    // dp에 저장된 값 중 가장 큰 값을 찾아서 출력
    res = dp[0][0];
    for (int column = 0; column < n; column++)
        for (int row = 0; row < 2; row++)
            if (dp[column][row] > res)
                res = dp[column][row];
    cout << res;

    return 0;
}