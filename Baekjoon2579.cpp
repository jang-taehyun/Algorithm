/*
problem : 수열 S가 주어졌을 때, 연속해서 3개 수를 고르지 않으면서 수열의 요소를 골라 합의 최대값을 구해라.
input : 수열 S
output : 연속해서 3개의 수를 고르지 않으면서 수열의 요소를 고른 후의 합의 최대값

idea
- dp[i] : i번째 요소를 골랐을 때, 합의 최대값
  dp[i] = max(dp[i-3]+s[i-1], dp[i-2]) + s[i];
*/
#include <iostream>
#include <algorithm>
using namespace std;

int input[300];            // 수열 S
int dp[300];               // dp

int main()
{
    int ArrayLength;           // 수열 S의 길이 

    // 수열 S 입력
    cin >> ArrayLength;
    for (int i = 0; i < ArrayLength; i++)
        cin >> input[i];

    // dp의 초기값 입력
    dp[0] = input[0];
    dp[1] = max(input[0], 0) + input[1];
    dp[2] = max(input[0], input[1]) + input[2];

    // 수열의 길이만큼 dp를 연산
    for (int i = 3; i < ArrayLength; i++)
        dp[i] = max(dp[i - 3] + input[i - 1], dp[i - 2]) + input[i];

    // 최대값 출력
    cout << dp[ArrayLength - 1];

    return 0;
}