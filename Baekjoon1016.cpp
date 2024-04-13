/*
problem : min�� max ���̿� �ִ� ���� �� 1���� ū �������� ������ �������� �ʴ� ������ ������ ���ض�.
input : min, max
output : min�� max ���̿� �ִ� ���� �� 1���� ū �������� ������ �������� �ʴ� ������ ����

idea : �����佺�׳׽��� ü�� Ȱ��
- ���� ���� ���ڰ� �������� �������������� ǥ���ϴ� ����
  1) min�� ������ k(k = l * l, l�� 2 �̻��� ����)�� ���� �� a�� ���Ѵ�.
     min / k = a
  2) �� a�� ������ k�� ���� �� b�� ���ϰ�, b�� min ~ max ������ ������ ������ Ȯ���Ѵ�.
     b = k * a, check(b, min ~ max)
  3) ���� b�� min ~ max ������ ������ ���� �ʴ´ٸ�, a�� 1�� �������� b�� ���� ���� ���Եǰ� �Ѵ�.
     check(b, min ~ max) == false --> a++
  4) b�� min ~ max ������ ������ ���ٸ�, a���� ������ 1�� ������Ű�鼭 (a * k)�� ���� �������� ����� ǥ�ø� �Ѵ�.
  5) l�� 1 ������Ű��, 1�� �������� �ٽ� �����Ѵ�.
- min�� max�� �ִ� 10^12 + 10^6���� �Էµ� �� �����Ƿ� �迭�� ũ�⸦ (10^6+1)������ �����ϰ�,
  index�� ((a * k) - min)�� ��Ÿ����.(�Ǵ� index�� (b - min)�� ��Ÿ���� �ȴ�.)

���� �ڷ� : https://chanhuiseok.github.io/posts/baek-16/
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

    // ���� �Է� �� ������� �ʱⰪ ����
    cin >> min >> max;
    IsNotDivideCount = max - min + 1;

    // ���� ���� ���� �������� ���� ��� ǥ��
    for (long long l = 2; l * l <= max; l++)
    {
        // 1�� ����
        k = l * l;
        a = min / k;

        // 2�� ����
        b = a * k;

        // 3�� ����
        while (b < min)
        {
            a++;
            b = a * k;
        }

        // 4�� ����
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

    // ����� ���
    cout << IsNotDivideCount;

    return 0;
}