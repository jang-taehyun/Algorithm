/*
problem : 자연수 n이 주어지고, n번까지 피보나치 수를 작동할 때 0과 1이 출력되는 횟수를 구해라.
input : 자연수 n
output : n번까지 피보나치 수를 작동할 때 0과 1이 출력되는 횟수

idea
- 자연수 n을 입력받기 전, 0~40까지 피보나치 수를 작동했을 때의 횟수를 구한다.
- 1의 출력 횟수를 d(n)이라고 하면,
  d(n) = d(n-1) + d(n-2)이고,
  0의 출력 횟수는 d(n-1)과 같다.
- 모두 연산한 다음 자연수 n을 입력받아 이미 연산된 결과값을 출력한다.
*/
#include <iostream>
using namespace std;

int DP[41];

int main()
{
    int test, input;

    DP[0] = 0;
    DP[1] = 1;

    // DP로 0~40까지 피보나치 수를 작동했을 때의 결과값을 연산
    for (int i = 2; i <= 40; i++)
        DP[i] = DP[i - 1] + DP[i - 2];

    // 테스트 횟수 입력
    cin >> test;

    while (test--)
    {
        // 자연수 n 입력
        cin >> input;

        // 결과값 출력
        if (!input)
            cout << 1 << ' ' << 0 << '\n';
        else
            cout << DP[input - 1] << ' ' << DP[input] << '\n';
    }

    return 0;
}