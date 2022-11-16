/*
problem : 정수 n을 나누기 2, 나누기 3, 빼기 1을 최소로 이용해 1로 만들기
input : 정수 n(1 <= n <= 10^6)
output : n을 1로 만드는 최소 횟수

idea : 1에서 n까지 1씩 증가하면서, 숫자가 만들어지는 최소 횟수 저장
점화식 : DP[n] = min(DP[n-1], DP[n/2], DP[n/3]) + 1
*/

#include <iostream>
using namespace std;

// 숫자(index)가 만들어지는 최소 횟수 저장
int DP[10000001];

// 최솟값 반환 함수
int MinimumNumber(int _n1, int _n2) { return _n1 < _n2 ? _n1 : _n2; }

int main()
{
	int inputNumber;
	cin >> inputNumber;

	// 1. 숫자 1이 만들어지는 최소 횟수(0번) 초기화
	DP[1] = 0;

	// 2. 숫자 2부터 시작해 n까지 1씩 증가
	for (int index = 2; index <= inputNumber; index++)
	{
		// 3. DP[index-1], DP[index/2], DP[index/3] 중 최소값을 찾아서 1을 더한 후 DP[index]에 저장
		DP[index] = DP[index - 1] + 1;
		if (!(index % 2))
			DP[index] = MinimumNumber(DP[index], DP[index / 2] + 1);
		if (!(index % 3))
			DP[index] = MinimumNumber(DP[index], DP[index / 3] + 1);
	}

	// 4. n을 만드는 최소값 출력
	cout << DP[inputNumber] << '\n';

	return 0;
}