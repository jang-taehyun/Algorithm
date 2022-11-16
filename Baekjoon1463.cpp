/*
problem : ���� n�� ������ 2, ������ 3, ���� 1�� �ּҷ� �̿��� 1�� �����
input : ���� n(1 <= n <= 10^6)
output : n�� 1�� ����� �ּ� Ƚ��

idea : 1���� n���� 1�� �����ϸ鼭, ���ڰ� ��������� �ּ� Ƚ�� ����
��ȭ�� : DP[n] = min(DP[n-1], DP[n/2], DP[n/3]) + 1
*/

#include <iostream>
using namespace std;

// ����(index)�� ��������� �ּ� Ƚ�� ����
int DP[10000001];

// �ּڰ� ��ȯ �Լ�
int MinimumNumber(int _n1, int _n2) { return _n1 < _n2 ? _n1 : _n2; }

int main()
{
	int inputNumber;
	cin >> inputNumber;

	// 1. ���� 1�� ��������� �ּ� Ƚ��(0��) �ʱ�ȭ
	DP[1] = 0;

	// 2. ���� 2���� ������ n���� 1�� ����
	for (int index = 2; index <= inputNumber; index++)
	{
		// 3. DP[index-1], DP[index/2], DP[index/3] �� �ּҰ��� ã�Ƽ� 1�� ���� �� DP[index]�� ����
		DP[index] = DP[index - 1] + 1;
		if (!(index % 2))
			DP[index] = MinimumNumber(DP[index], DP[index / 2] + 1);
		if (!(index % 3))
			DP[index] = MinimumNumber(DP[index], DP[index / 3] + 1);
	}

	// 4. n�� ����� �ּҰ� ���
	cout << DP[inputNumber] << '\n';

	return 0;
}