/*
problem : n개의 카드를 사는 방법 중 카드가 i개 들어있는 카드팩의 가격 pi의 합이 최소가 되도록 구매하는 방법
input : 구매할 카드의 개수 n, 카드팩의 가격 pi
output : n개의 카드를 최소한의 비용으로 구매하는 방법

idea : All pair shortest problem의 solution을 이용
1. n=4이고 p1 = 5, p2 = 2, p3 = 8, p4 = 10일 때 최소한의 비용으로 구매하는 방법 구하기
   1) k=1일 때, 결과는 5
      -> p1을 1개 사는 방법
   2) k=2일 때, 결과는 2
      -> k=1일 때 구매한 방법에 p1을 같이 사는 방법(5+5), p2를 1개 사는 방법(2) 중 최소값을 고른다.
   3) k=3일 때, 7
      -> k=1일 때 구매한 방법에 p2을 같이 사는 방법(5+2),
         k=2일 때 구매한 방법에 p1을 같이 사는 방법(2+5),
         p3를 1개 사는 방법(8) 중 최소값을 고른다.
   4) k=4일 때, 4
      -> k=1일 때 구매한 방법에 p3을 같이 사는 방법(5+8),
         k=2일 때 구매한 방법에 p2을 같이 사는 방법(2+2),
         k=3일 때 구매한 방법에 p1을 같이 사는 방법(7+5),
         p4를 1개 사는 방법(10) 중 최소값을 고른다.
2. 이를 이용해 관계식을 정립
   -> DP[n] = minimum(DP[n-k]+pk, pn)
      -> 1 <= k <= n-1
      -> DP[1] == p1
*/

#include <iostream>
using namespace std;

// 최소값을 반환하는 함수
int MinimumNumber(int _x, int _y) { return _x < _y ? _x : _y; }

int main()
{
    // 구매할 카드의 개수 N
    int N = 0;
    // i개의 카드가 들어있는 카드팩의 가격 DP[i]
    int price[1001];
    // i개의 카드를 사기 위해 지불하는 최소 비용
    int DP[1001];

    // N과 pi 입력
    cin >> N;
    for (int index = 1; index <= N; index++)
        cin >> price[index];

    // i개의 카드를 사기 위해 지불하는 최소 비용을 i개의 카드가 들어있는 카드팩의 가격으로 초기화
    for (int i = 1; i <= N; i++)
        DP[i] = price[i];

    // i가 2부터 시작해 n까지, 관계식을 이용해 지불할 최소 비용 계산
    for (int i = 2; i <= N; i++)
        // k가 1부터 시작해 i-1까지, 최소값을 찾아 DP에 저장
        for (int k = 1; k < i; k++)
            DP[i] = MinimumNumber(DP[i - k] + price[k], DP[i]);

    // 결과값 출력
    cout << DP[N];

    return 0;
}