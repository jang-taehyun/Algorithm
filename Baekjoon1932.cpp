/*
problem : 크기가 n인 정수 삼각형이 있을 때, 맨 위층에서 시작하여 이제까지 선택된 수의 합이 최대가 되는 경로를 구하라.
input : 정수 삼각형의 크기 n, 삼각형을 이루고 있는 정수 i(1 <= n <= 500, 0 <= i <= 9999)
output : 맨 위층에서 맨 아래까지 가는 경로 중 선택된 수의 합의 최대값

idea
- 크기가 5인 정수 삼각형이 아래와 같이 주어졌다고 하자. 여기서 (i, j)는 i번째 column에서 존재하는 정수들 중 j번째 정수를 의미한다.
      7
     3 8
    8 1 0
   2 7 4 4
  4 5 2 6 5
- 여기에서 3번째 column에서 다음과 같은 경우가 발생한다.
  1) (3, 1) : (2, 1)에서 얻어진 최대값 + (3, 1)
  2) (3, 2) : max{(2, 1)에서 얻어진 최대값, (2, 2)에서 얻어진 최대값} + (3, 2)
  3) (3, 3) : (2, 2)에서 얻어진 최대값 + (2, 2)
- 즉, i번째 column에서는 다음과 같은 경우가 발생한다.
  1) j가 1인 경우 : (i-1, 1)에서 얻어진 최대값 + (i, j)
  2) j와 i가 같은 경우 : (i-1, j-1)에서 얻어진 최대값 + (i, j)
  3) 그외 : max{(i-1, j-1)에서 얻어진 최대값, (i-1, j)에서 얻어진 최대값} + (i, j)
- 이를 이용해 관계식 도출
  dp[i][j] : 현재 경로(i, j)까지 왔을 때 얻을 수 있는 최대값
  j == 1 : dp[i-1][j] + value[i][j];
  j == i : dp[i-1][j-1] + value[i][j];
  그 외   : max(dp[i-1][j-1], dp[i-1][j]) + value[i][j]
- 관계식을 2부터 n까지 반복문을 돌면서 계산하고, 반복문이 끝나면 n번째 column에서 존재하는 수 중 최대값을 찾는다.
*/

#include <iostream>
#include <cstring>
using namespace std;

int Max(int x, int y) { return x > y ? x : y; }

int main()
{
    // 정수 삼각형의 크기 n
    int n = 0;
    // 정수 삼각형에 들어가는 정수 2차원 배열 value
    int value[500][500];
    // 관계식을 이용해 현재 경로까지 얻을 수 있는 최대값 2차원 배열 dp
    int dp[500][500];
    // 최대값 res
    int res = 0;

    // value와 dp 초기화
    memset(value, 0, sizeof(value));
    memset(dp, 0, sizeof(dp));

    // 정수 삼각형의 크기 n과 삼각형에 들어가는 정수 입력
    cin >> n;
    for (int column = 0; column < n; column++)
        for (int row = 0; row < column + 1; row++)
            cin >> value[column][row];

    // 정수 삼각형의 맨 위층으로 dp 초기화
    dp[0][0] = value[0][0];

    // 1번째 column부터 시작해 n번째 column까지 관계식을 이용해 현재 경로까지 얻어진 최대값 계산
    for (int column = 1; column < n; column++)
        for (int row = 0; row < column + 1; row++)
        {
            if (row == 0)
                dp[column][row] = dp[column - 1][row];
            else if (row == column)
                dp[column][row] = dp[column - 1][row - 1];
            else
                dp[column][row] = max(dp[column - 1][row - 1], dp[column - 1][row]);

            dp[column][row] += value[column][row];
        }

    // dp에서 n번째 column에 저장된 값 중 최대값을 찾아 출력
    for (int i = 0; i < n; i++)
        if (res < dp[n - 1][i])
            res = dp[n - 1][i];
    cout << res;

    return 0;
}