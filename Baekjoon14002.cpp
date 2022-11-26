/*
problem : 수열 A의 가장 긴 증가하는 부분 수열을 구해라
input : 수열 A
output : 가장 긴 증가하는 부분 수열 R, 가장 긴 증가하는 부분 수열의 길이 l

idea
1. A = {10, 20, 10, 30, 20, 50}이라고 하고, 각각의 요소들을 a1, a2, a3, a4, a5, a6라고 하자
2. a1을 맨 오른쪽에 반드시 포함하는 가장 긴 부분 수열 구하기
   -> 자기 자신을 포함하는 방법밖에 없다.
      R={10}, l=1
3. a2을 맨 오른쪽에 반드시 포함하는 가장 긴 부분 수열 구하기
   -> a2=20는 a1보다 크므로, a1을 통해 만든 가장 긴 부분 수열을 이용할 수 있다.
      R={10, 20}, l=2
4, a3을 맨 오른쪽에 반드시 포함하는 가장 긴 부분 수열 구하기
   -> a3=10는 a1과 같고 a2보다 작으므로, a1 또는 a2를 통해 만든 가장 긴 부분 수열을 이용할 수 없다.
      따라서 자기 자신을 포함하는 방법밖에 없다.
      R={10}, l=1
5. a4을 맨 오른쪽에 반드시 포함하는 가장 긴 부분 수열 구하기
   -> a4=30는 a1,a2,a3보다 크므로, a1, a2, a3를 통해 만든 가장 긴 부분 수열을 이용할 수 있다.
      이 중 가장 긴 부분수열은 a2를 통해 만든 가장 긴 부분 수열 {10, 20}이므로 이를 이용한다.
      R={10,20,30}, l=3
6. 이 과정을 이용해 관계식 도출
   -> DP[i] : ai을 맨 오른쪽에 반드시 포함하는 가장 긴 부분 수열의 길이
      DP[i] = max(DP[k]) + 1 (1 <= k <= i-1 중 ak<ai인 경우가 존재할 때)
              1              (1 <= k <= i-1 중 ak<ai인 경우가 존재하지 않을 때)
7. 부분 수열의 요소들도 출력해야 하므로, 2차원 배열을 이용
   DP[i][0] : ai를 맨 오른쪽에 반드시 포함하는 가장 긴 부분 수열의 길이 l
   DP[i][1] ~ DP[i][l] : ai를 맨 오른쪽에 반드시 포함하는 가장 긴 부분 수열의 요소
*/

#include <iostream>
using namespace std;

int main()
{
    // 수열의 크기 N
    int N;
    // 수열을 저장할 배열 A, 입력값이 1000을 넘지 않으므로 배열의 길이를 1001로 두고 index 0은 비워둔다.
    int A[1001];
    // 가장 긴 부분 수열의 길이와 요소를 저장할 2차원 배열 DP
    int DP[1001][1001];

    // 수열의 크기와 요소 입력
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    // DP[1] = 1이므로 이를 초기화
    DP[1][0] = 1;
    DP[1][1] = A[1];

    // 관계식을 이용해 a2부터 aN까지 가장 긴 부분 수열 구하기
    for (int index = 2; index <= N; index++)
    {
        // ai를 맨 오른쪽에 반드시 포함하는 가장 긴 부분수열의 길이를 0으로 초기화
        DP[index][0] = 0;

        // ai보다 작은 것들 중 가장 긴 부분 수열을 가진 index를 저장
        int longestIndex = 0;

        // 1~(i-1) 중 ai보다 작으면 관계식을 이용해 수열의 길이 저장 및 index값 저장
        for (int j = 1; j < index; j++)
        {
            bool isSmaller = A[j] < A[index];
            bool isBigger = DP[j][0] > DP[index][0];
            if (isSmaller && isBigger)
            {
                DP[index][0] = DP[j][0];
                longestIndex = j;
            }
        }

        // 수열에 자기 자신을 포함하므로 길이에 1증가
        DP[index][0]++;

        // 수열의 요소 저장
        for (int j = 1; j <= DP[longestIndex][0]; j++)
            DP[index][j] = DP[longestIndex][j];
        DP[index][DP[index][0]] = A[index];
    }

    // 가장 긴 부분 수열의 길이를 찾고 출력
    int longestIndex = 1;
    for (int i = 2; i <= N; i++)
        longestIndex = DP[i][0] > DP[longestIndex][0] ? i : longestIndex;

    cout << DP[longestIndex][0] << '\n';
    for (int i = 1; i <= DP[longestIndex][0]; i++)
        cout << DP[longestIndex][i] << ' ';

    return 0;
}