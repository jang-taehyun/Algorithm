/*
problem : min과 max 사이에 있는 정수 중 1보다 큰 제곱수로 나누어 떨어지지 않는 정수의 개수를 구해라.
input : min, max
output : min과 max 사이에 있는 정수 중 1보다 큰 제곱수로 나누어 떨어지지 않는 정수의 개수

idea : 에라토스테네스의 체를 활용
- 범위 내의 숫자가 제곱수로 나눠떨어지는지 표시하는 과정
  1) min을 제곱수 k(k = l * l, l은 2 이상의 정수)로 나눠 몫 a을 구한다.
     min / k = a
  2) 몫 a에 제곱수 k를 곱한 값 b를 구하고, b가 min ~ max 사이의 범위에 들어가는지 확인한다.
     b = k * a, check(b, min ~ max)
  3) 만약 b가 min ~ max 사이의 범위에 들어가지 않는다면, a를 1씩 증가시켜 b가 범위 내에 포함되게 한다.
     check(b, min ~ max) == false --> a++
  4) b가 min ~ max 사이의 범위에 들어간다면, a부터 시작해 1씩 증가시키면서 (a * k)가 나눠 떨어지는 수라는 표시를 한다.
  5) l을 1 증가시키고, 1번 과정부터 다시 시작한다.
- min과 max에 최대 10^12 + 10^6까지 입력될 수 있으므로 배열의 크기를 (10^6+1)개까지 선언하고,
  index는 ((a * k) - min)로 나타낸다.(또는 index를 (b - min)로 나타내도 된다.)

참고 자료 : https://chanhuiseok.github.io/posts/baek-16/
*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    long long min, max;
    long long a, b, k;
    bool IsDivide[1000001];
    long long IsNotDivideCount;

    memset(IsDivide, false, sizeof(IsDivide));

    // 범위 입력 및 결과값의 초기값 세팅
    cin >> min >> max;
    IsNotDivideCount = max - min + 1;

    // 범위 내에 나눠 떨어지는 수를 모두 표시
    for (long long l = 2; l * l <= max; l++)
    {
        // 1번 과정
        k = l * l;
        a = min / k;

        // 2번 과정
        b = a * k;

        // 3번 과정
        while (b < min)
        {
            a++;
            b = a * k;
        }

        // 4번 과정
        while (b <= max)
        {
            if (!IsDivide[b - min])
            {
                IsDivide[b - min] = true;
                IsNotDivideCount--;
            }

            a++;
            b = a * k;
        }
    }

    // 결과값 출력
    cout << IsNotDivideCount;

    return 0;
}