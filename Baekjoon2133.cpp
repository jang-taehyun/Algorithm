/*
problem : 3*n 크기의 벽을 2*1, 1*2 크기의 타일로 채우는 경우의 수를 구해라.
inpuut : 벽의 row의 크기 n
output : 3*n 크기의 벽을 2*1, 1*2 크기의 타일로 채우는 경우의 수

idea
- n=0일 때 경우의 수를 1이라고 하자.
  -> 아무것도 채우지 않는 방법이 있기 때문
- n=1일 때 경우의 수 : 없음
- n=2일 때 경우의 수 : 3
- n=3일 때 경우의 수 : 없음
- n=4일 때 경우의 수 : 11
  - (n=2)일 때 경우의 수 * (n=2)일 때 경우의 수 = 9
  - (n=4)에서 나오는 특별한 모양의 개수 = 2
- n=5일 때 경우의 수 : 0
- n=6일 때 경우의 수
  - (n=2)일 때 경우의 수 * (n=4)일 때 경우의 수 : 33
  - (n=4)에서 나오는 특별한 모양의 개수 * (n=2)일 때 경우의 수 : 6
  - (n=6)에서 나오는 특별한 모양의 개수 : 2
- 이를 통해 관계식 도출
  - dp[i] : 3*i 크기의 벽을 2*1, 1*2 크기의 타일로 채우는 경우의 수
  - dp[i] = dp[i-2]*dp[2] + dp[i-4]*2 + dp[i-6]*2 + ... + dp[0]*2
- 4부터 n까지 관계식을 이용해 벽을 채우는 경우의 수를 구하고 출력
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // 벽의 row 크기 n
    int n = 0;
    // 3*n 크기의 벽을 2*1, 1*2 크기의 타일로 채우는 경우의 수 dp
    int dp[31];

    // dp 초기화 및 벽의 row 크기 n 입력
    memset(dp, 0, sizeof(dp));
    cin >> n;

    // n=0, n=2 일때 초기화
    dp[0] = 1;
    dp[2] = 3;

    // 4부터 n까지 관계식을 이용해 벽을 채우는 경우의 수 계산
    for (int currentRow = 4; currentRow <= n; currentRow += 2)
    {
        dp[currentRow] = dp[currentRow - 2] * dp[2];
        for (int prevRow = currentRow - 4; prevRow > -1; prevRow -= 2)
            dp[currentRow] += (dp[prevRow] * 2);
    }

    // 결과값 출력
    cout << dp[n];

    return 0;
}