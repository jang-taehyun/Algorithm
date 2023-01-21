/*
problem : 양수 m, n보다 작은 양수 x, y로 표현된 년도 k를 구해라.
input : 양수 m, n, x, y (1<=m,n<=40000, 1<=x<=m, 1<=y<=n)
output : 양수 x, y로 표현된 년도 k

idea : k=x부터 시작하여, k를 n으로 나눈 나머지가 y인지 확인한다.
이때, k가 m과 n의 최소공배수를 넘어가면 -1로 출력한다.
*/
#include <iostream>
using namespace std;

// m과 n의 최소공배수를 구하는 LeastCommonMultiple function
int LeastCommonMultiple(int m, int n)
{
    // 유클리드 호제법을 이용해 m과 n의 최대공약수를 구한다.
    int gcd = m;
    int division = n;

    while (division)
    {
        int remainder = gcd % division;
        gcd = division;
        division = remainder;
    }

    // m과 n의 최소공배수를 구하고 return
    return (m * n) / gcd;
}

int main()
{
    // 테스트할 횟수 testcase
    int testcase = 0;
    // 양수 m, n, x, y
    int m = 0, n = 0, x = 0, y = 0;
    // 양수 m과 n의 최소공배수 bound
    int bound = 0;
    // 양수 x, y로 표현된 연도 k
    int k = 0;

    // 테스트할 횟수 testcase 입력
    cin >> testcase;

    while (testcase--)
    {
        // 양수 m, n, x, y 입력
        cin >> m >> n >> x >> y;

        // 연도 k, m과 n의 최소공배수 bound 초기화
        k = x;
        bound = LeastCommonMultiple(m, n);

        // k를 m씩 증가하면서, k를 n으로 나눈 몫이 y인지 확인
        while (true)
        {
            int ny = k % n;
            if (!ny)
                ny = n;

            if (ny == y)
                break;

            k += m;

            // 만약 k가 m과 n의 최소공배수 bound를 넘어가면 -1로 설정하고 while문을 빠져나온다.
            if (k > bound)
            {
                k = -1;
                break;
            }
        }

        // 결과 출력
        cout << k << '\n';
    }

    return 0;
}