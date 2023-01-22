/*
problem : 1부터 n까지의 숫자를 이어붙여 만들어진 양수는 몇 자리 수인지 구해라
input : 이어붙일 숫자의 개수 n
output : 1부터 n까지의 숫자를 이어붙여 만들어진 양수의 자리수

idea
- n이 1~9사이에 있는 경우(n이 1자리인 경우) : 1*n
- n이 10~99사이에 있는 경우(n이 2자리인 경우) : 1*9 + 2*(n-10+1)
- n이 100~999사이에 있는 경우(n이 3자리인 경우) : 1*9 + 2*(99-10+1) + 3*(n-100+1)
- n이 k자리인 경우 : 1*9 + 2*90 + 3*900 + ... + k(n-10^k+1)
- 이러한 관계를 이용해 문제를 해결한다.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 이어붙일 숫자 n
    int n = 0;
    // 범위의 시작인 정수 first
    int first = 1;
    // 범위의 마지막 정수 last
    int last = 9;
    // n의 길이 numberlength == k
    int numberlength = 0;
    // 현재 탐색하고 있는 숫자의 길이 length
    int length = 1;
    // 결과값 res
    int res = 0;

    // n 입력
    cin >> n;

    // numberlength 초기화
    numberlength = to_string(n).length();

    // length-1 자리까지 구해지는 자릿수 계산
    for (length = 1; length < numberlength; length++)
    {
        res += (length * (last - first + 1));

        // first, last 업데이트
        first *= 10;
        last = last * 10 + 9;
    }

    // k 자리에서 구해지는 자릿수까지 합산
    res += (numberlength * (n - first + 1));

    // 결과값 출력
    cout << res;

    return 0;
}