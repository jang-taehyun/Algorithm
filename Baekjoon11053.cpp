/*
problem : 수열 A의 가장 긴 증가하는 부분 수열을 구해라
input : 수열 A
output : 수열 A의 가장 긴 증가하는 부분 수열의 길이 k

idea
1. A = {10, 20, 10, 30, 20}이라고 하고, 각각 a1, a2, a3, a4, a5라고 하자
2. a1=10을 맨 오른쪽에 반드시 포함해서 만들 수 있는 가장 긴 증가하는 부분 수열은 {10} 하나이므로 k=1
2. a2=20을 맨 오른쪽에 반드시 포함해서 만들 수 있는 가장 긴 증가하는 부분 수열 구하기
   -> a2는 a1보다 크므로, 이전 것인 a1을 만들 수 있는 가장 긴 증가하는 부분 수열에 a2를 추가하는 것이므로 k=2
3. a3=10을 맨 오른쪽에 반드시 포함해서 만들 수 있는 가장 긴 증가하는 부분 수열 구하기
   -> a1, a2 중 a3 보다 작은 것은 없으므로, 자기 자신만 있는 수열이 가장 긴 증가하는 부분 수열이므로 k=1
4. a4=30을 맨 오른쪽에 반드시 포함해서 만들 수 있는 가장 긴 증가하는 부분 수열 구하기
   -> a1, a2, a3는 모두 a4보다 작으므로 이 중 가장 긴 증가하는 부분 수열에서 a4를 오른쪽에 붙인다
   1) 1단계에서 a4를 추가하는 방법 k=2
   2) 2단계에서 a4를 추가하는 방법 k=3
   3) 3단계에서 a4를 추가하는 방법 k=2
   -> k=3
5. a5=20을 맨 오른쪽에 반드시 포함해서 만들 수 있는 가장 긴 증가하는 부분 수열 구하기
   -> a1, a2, a3, a4 중 a5보다 작은 것은 a1, a3이므로 이 중 가장 긴 증가하는 부분 수열을 구해 a5를 오른쪽에 붙인다.
   1) 1단계에서 a5를 추가하는 k=2
   2) 3단계에서 a5를 추가하는 k=2
   -> k=2
6. 이 단계를 통해 만들어진 k 중 최대값을 출력한다.
   -> k=3
7. 이를 이용해 관계식 도출
   -> DP[i] : a1부터 a(i-1)에서, ai보다 작은 요소를 이용하고 ai를 반드시 포함해서 만들 수 있는 가장 긴 증가하는 부분 수열의 길이
      DP[i] = max(DP[k]) + 1 (ak<ai인 k가 존재할 때)
              1              (ak<ai인 k가 존재하지 않을 때 or i=1일 때)
*/
#include <iostream>
using namespace std;

int Max(int _x, int _y) { return _x > _y ? _x : _y; }

int main()
{
    // 수열의 크기 N
    int N = 0;
    // 수열을 저장할 배열 A, 수열의 개수는 1000개까지 주어지므로 배열의 크기는 1000으로 한다.
    int A[1000];
    // ai를 맨 오른쪽에 반드시 포함해서 만들 수 있는 가장 긴 증가하는 부분 수열의 길이를 저장할 배열 DP
    int DP[1000];
    // DP 중 가장 큰 값을 저장
    int result = 0;

    // 수열의 크기와 수열의 요소 입력
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    // i=1일 때 DP 초기화
    DP[0] = 1;

    // i=2부터 i=N까지 ai를 맨 오른쪽에 반드시 포함해 만들 수 있는 가장 긴 증가하는 부분 수열의 길이를 구한다.
    for (int i = 1; i < N; i++)
    {
        // DP를 먼저 초기화 한 후,
        DP[i] = 0;
        // 1부터 i-1까지 ai보다 작은 요소를 찾아, 그 중 최대값을 찾는다.
        for (int j = 0; j < i; j++)
            if (A[j] < A[i])
                DP[i] = Max(DP[i], DP[j]);
        // 만약 ai보다 작은 요소가 없다면 DP는 1로 설정하고, 있다면 거기에 1을 더한다.
        DP[i]++;
    }

    // DP[0]부터 DP[N-1] 중 가장 큰 값을 찾아 출력
    for (int i = 0; i < N; i++)
        result = Max(result, DP[i]);
    cout << result;

    return 0;
}