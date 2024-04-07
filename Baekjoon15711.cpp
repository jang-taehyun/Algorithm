/*
problem : �� ���� ���ڸ� ���ϰ� �ٽ� 2���� �Ҽ��� ���� �� �ִ��� �Ǻ��ض�.
input : 2���� ����
output : �� ���� ���ڸ� ���ϰ� �ٽ� 2���� �Ҽ��� ���� �� �ִ��� ����

idea
- �Ҽ��� �����佺�׳׽��� ü�� �̿��� 2*10^6���� ���Ѵ�.
- �� ���� ���ڸ� ���� ����� ¦����� ������ 2���� �Ҽ��� ���� �� �ִ�.(�������� ����)
- �� ���� ���ڸ� ���� ����� Ȧ����� (2+�Ҽ�)�� ���� �� �ִ��� Ȯ���Ѵ�.
*/
#include <iostream>
#include <vector>
#define BOUND 2000001
using namespace std;

bool IsNotPrimary[BOUND];        // �Ҽ����� �ƴ��� ����

int main()
{
    int test;
    long long input1, input2;
    long long sum;
    vector<int> prime;
    bool IsAble = true;

    // �����佺�׳׽��� ü�� �̿��� 2*10^6������ ������ ���� �� �Ҽ��� ã�� ���� ����
    for (int i = 2; i * i < BOUND; i++)
        if (!IsNotPrimary[i])
            for (int j = i * i; j < BOUND; j += i)
                IsNotPrimary[j] = true;

    for (long long i = 2; i < BOUND; i++)
        if (!IsNotPrimary[i])
            prime.push_back(i);

    // �׽�Ʈ���̽� Ƚ�� �Է�
    cin >> test;

    while (test--)
    {
        // �� ���� �� �Է�
        cin >> input1 >> input2;

        sum = (long long)input1 + input2;

        // �Ǻ�
        // ���� 2 �Ǵ� 3�� ���
        if (sum == 2 || sum == 3)
            cout << "NO" << '\n';
        // ���� ¦���� ���
        else if (!(sum % 2))
            cout << "YES" << '\n';
        // ���� Ȧ���� ���
        else if (sum % 2)
        {
            sum -= 2;
            IsAble = true;

            // (sum-2)�� ����� �Ҽ��� ���������� Ȯ��
            for (int i = 0; i < prime.size() && (long long)prime[i] * prime[i] <= sum; i++)
            {
                if (!(sum % prime[i]))
                {
                    cout << "NO" << '\n';
                    IsAble = false;
                    break;
                }
            }

            if (IsAble)
                cout << "YES" << '\n';
        }

    }

    return 0;
}