/*
problem : n개의 숫자를 가진 수열 S가 주어졌을 때, 수열 S 안에 숫자를 가장 적게 넣어 각 요소 사이의 차이가 같게 만들어라.
          같게 만든 후에 넣은 숫자의 개수 중 최소값을 구해라.
input : 수열 S
output : 수열 S 안에 숫자를 넣어 각 요소 사이의 차이가 같게 만들 때, 넣은 개수 중 최소값

idea
- 수열 S 안에 숫자를 넣으면서 요소들 간의 최대공약수(GCD)를 구한다.
- (각 요소들 간의 거리 / GCD - 1)를 결과값에 누적합을 한다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef unsigned int uint;

int GCD(int x, int y)
{
    if (!(x % y))
        return y;
    return GCD(y, x % y);
}

int main()
{
    vector<uint> s;                    // 수열 S
    uint ArraySize;                    // 수열 S의 길이
    uint param1, param2, param3;       // 초기 입력값
    uint diff1, diff2;                 // 초기 요소 사이의 거리
    uint gcd;                          // 최대공약수
    uint res = 0;

    // 수열 S 입력하면서 요소들 간의 거리들의 GCD 구하기
    cin >> ArraySize;
    cin >> param1 >> param2 >> param3;
    s.push_back(param1);
    s.push_back(param2);
    s.push_back(param3);
    diff1 = param2 - param1;
    diff2 = param3 - param2;

    gcd = GCD(diff1, diff2);

    for (uint i = 3; i < ArraySize; i++)
    {
        cin >> param1;
        s.push_back(param1);

        // GCD 구하기
        diff1 = max(param1 - param2, gcd);
        diff2 = min(param1 - param2, gcd);
        gcd = GCD(diff1, diff2);

        // 설정값 update
        param2 = param1;
    }

    // 구한 GCD를 이용해 수열 S에 넣는 숫자의 최소 개수 구하기
    for (uint i = 1; i < ArraySize; i++)
        res += ((s[i] - s[i - 1]) / gcd) - 1;

    // 결과 출력
    cout << res;

    return 0;
}