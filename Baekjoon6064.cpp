/*
problem : ��� m, n���� ���� ��� x, y�� ǥ���� �⵵ k�� ���ض�.
input : ��� m, n, x, y (1<=m,n<=40000, 1<=x<=m, 1<=y<=n)
output : ��� x, y�� ǥ���� �⵵ k

idea : k=x���� �����Ͽ�, k�� n���� ���� �������� y���� Ȯ���Ѵ�.
�̶�, k�� m�� n�� �ּҰ������ �Ѿ�� -1�� ����Ѵ�.
*/
#include <iostream>
using namespace std;

// m�� n�� �ּҰ������ ���ϴ� LeastCommonMultiple function
int LeastCommonMultiple(int m, int n)
{
    // ��Ŭ���� ȣ������ �̿��� m�� n�� �ִ������� ���Ѵ�.
    int gcd = m;
    int division = n;

    while (division)
    {
        int remainder = gcd % division;
        gcd = division;
        division = remainder;
    }

    // m�� n�� �ּҰ������ ���ϰ� return
    return (m * n) / gcd;
}

int main()
{
    // �׽�Ʈ�� Ƚ�� testcase
    int testcase = 0;
    // ��� m, n, x, y
    int m = 0, n = 0, x = 0, y = 0;
    // ��� m�� n�� �ּҰ���� bound
    int bound = 0;
    // ��� x, y�� ǥ���� ���� k
    int k = 0;

    // �׽�Ʈ�� Ƚ�� testcase �Է�
    cin >> testcase;

    while (testcase--)
    {
        // ��� m, n, x, y �Է�
        cin >> m >> n >> x >> y;

        // ���� k, m�� n�� �ּҰ���� bound �ʱ�ȭ
        k = x;
        bound = LeastCommonMultiple(m, n);

        // k�� m�� �����ϸ鼭, k�� n���� ���� ���� y���� Ȯ��
        while (true)
        {
            int ny = k % n;
            if (!ny)
                ny = n;

            if (ny == y)
                break;

            k += m;

            // ���� k�� m�� n�� �ּҰ���� bound�� �Ѿ�� -1�� �����ϰ� while���� �������´�.
            if (k > bound)
            {
                k = -1;
                break;
            }
        }

        // ��� ���
        cout << k << '\n';
    }

    return 0;
}