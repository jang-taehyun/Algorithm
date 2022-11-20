/*
problem : 카드팩의 갯수가 1부터 n까지 있고, 각각의 카드팩마다 가격 pi가 주어졌을 때, n개의 카드를 사는 최대값
input : 구매하려는 카드의 개수 n, 카드팩마다의 가격 pi
output : n개의 카드를 구매하기 위해 지불하는 최대값

idea : All pair shortest problem의 변형
1. n=4이고, pi가 1, 5, 6, 7일 때 최댓값을 구하는 방법
   1) i=1일 때, max=1
      -> p1 = 1
   2) i=2일 때, max=5
      -> max1 + max1 = 2, p2 = 5 중 max = 5
   3) i=3일 때, max=6
      -> max1 + max1 + max1 = 3, max2 + max1 = 6, p3 = 6 중 max=6
   4) i=4일 때, max=7
      -> max1 + max1 + max1 + max1 = 4, max2 + max2 = 10, max3 + max1 = 7, p4 = 7 중 max=10
2. 이를 이용해 관계식 정립
   -> Max[n] = maximum(pn, Max[n-k] + Max[k]) (1 <= k <= n-1)
      -> Max[1] = p1
*/

#include <iostream>
#include <cstring>
using namespace std;

// 큰 값을 찾아 반환하는 함수
int Max(int _x, int _y) { return _x > _y ? _x : _y; }

int main()
{
    // 입력받을 n
    int inputNumber = 0;
    // price을 입력받고, max을 저장할 배열
    // 입력값이 1001을 넘지 않으므로, 배열의 크기를 1001로 지정
    int DP[1001];

    cin >> inputNumber;
    for (int i = 1; i <= inputNumber; i++)
        cin >> DP[i];

    // n이 2부터 inputNumber까지, max값을 저장한다.
    for (int n = 2; n <= inputNumber; n++)
        // k=1부터 n-1까지 DP에 저장된 값과 비교한 후 큰 값을 DP에 저장한다.
        for (int k = 1; k <= n / 2; k++)
            DP[n] = Max(DP[n], DP[n - k] + DP[k]);

    // 최댓값 출력
    cout << DP[inputNumber];

    return 0;
}