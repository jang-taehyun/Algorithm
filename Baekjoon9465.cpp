/*
problem : 2*n으로 배치된 스티커는 한 번 떼어내면, 뗀 스티커의 상하좌우는 사용할 수 없다.
이때, 뗄 수 있는 스티커의 합 중 최댓값을 구해라.
input : 테스트할 횟수 T, 가로의 길이 n(1 <= n <= 100000), 스티커의 점수 p(0 <= p <= 100)
output : 뗄 수 있는 스티커의 합 중 최댓값

idea
- 스티커가 다음과 같이 배열되어 있다고 하자.
  50 10 100 20 40
  30 50  70 10 60
- 여기에서 n=2일 때 나타나는 경우는 다음과 같다.
  1) '10'을 고르기 위해서는, n=1에서 아래 스티커(30)을 고르거나 n=1에서 스티커를 고르지 않아야 한다.
     때문에 '10'을 선택할 때 나오는 최대값은 '30 + 10' 또는 '0 + 10'이다.
  2) '50'을 고르기 위해서는, n=1에서 위 스티커(50)을 고르거나 n=1에서 스티커를 고르지 않아야 한다.
     때문에 '50'을 선택할 때 나오는 최대값은 '50 + 50' 또는 '0 + 50'이다.
  3) n=2일 때 '아무것도 선택하지 않다'면, n=1에서 위 스티커(50) 또는 아래 스티커(30)을 고를 수 있다.
     때문에 '아무것도 선택하지 않는'다면 나올 수 있는 최대값은 '50 + 0' 또는 '30 + 0'이다.
- 이를 이용해 관계식을 도출한다.
  - dp[i][j] : i번째 row에서 j 경우를 선택할 때 나오는 최대값
    -> j 경우 : 0(위 스티커 선택), 1(아래 스티커 선택), 2(아무것도 선택하지 않음)
    dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + 위 스티커의 value
    dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + 아래 스티커의 value
    dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + 0
- 이를 n까지 반복한 후, n에서 위 스티커를 고르는 경우, n에서 아래 스티커를 고르는 경우, n에서 아무것도 선택하지 않는 경우 중
  최대값을 골라 출력한다.
*/

#include <iostream>
#include <cstring>
using namespace std;

// 최대값 반환 함수
int max(int x, int y) { return x > y ? x : y; }

int main()
{
    // 테스트할 횟수 T
    int T = 0;
    // row의 길이 n
    int n = 0;
    // 스티커의 value를 저장할 2차원 배열 value
    // 1부터 시작하기 위해 row의 크기를 100001로 지정
    int value[2][100001];
    // 최대값을 저장할 2차원 배열 dp
    // 2차원 배열의 value의 row 크기가 100001이므로, dp의 column을 똑같이 지정
    int dp[100001][3];
    // 최대값 저장
    int res = 0;

    // value와 dp 초기화
    memset(value, 0, sizeof(dp));
    memset(dp, 0, sizeof(dp));

    // 테스트할 횟수 입력
    cin >> T;

    // 테스트할 횟수만큼 반복
    while (T--)
    {
        // row의 길이 입력
        cin >> n;

        // 스티커의 value 입력
        for (int column = 0; column < 2; column++)
            for (int row = 1; row <= n; row++)
                cin >> value[column][row];

        // n=1일 때 dp 초기화
        dp[1][0] = value[0][1];
        dp[1][1] = value[1][1];
        dp[1][2] = 0;

        // 2부터 n까지 관계식을 이용해 각 경우의 최대값 계산
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + value[0][i];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + value[1][i];
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
        }

        // 결과값 출력
        res = dp[n][0];
        for (int i = 1; i < 3; i++)
            if (res < dp[n][i])
                res = dp[n][i];
        cout << res << '\n';

        // value와 dp 초기화
        memset(value, 0, sizeof(dp));
        memset(dp, 0, sizeof(dp));
        res = 0;
    }

    return 0;
}