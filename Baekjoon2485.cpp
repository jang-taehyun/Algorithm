/*
problem : n���� ���ڸ� ���� ���� S�� �־����� ��, ���� S �ȿ� ���ڸ� ���� ���� �־� �� ��� ������ ���̰� ���� ������.
          ���� ���� �Ŀ� ���� ������ ���� �� �ּҰ��� ���ض�.
input : ���� S
output : ���� S �ȿ� ���ڸ� �־� �� ��� ������ ���̰� ���� ���� ��, ���� ���� �� �ּҰ�

idea
- ���� S �ȿ� ���ڸ� �����鼭 ��ҵ� ���� �ִ�����(GCD)�� ���Ѵ�.
- (�� ��ҵ� ���� �Ÿ� / GCD - 1)�� ������� �������� �Ѵ�.
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
    vector<uint> s;                    // ���� S
    uint ArraySize;                    // ���� S�� ����
    uint param1, param2, param3;       // �ʱ� �Է°�
    uint diff1, diff2;                 // �ʱ� ��� ������ �Ÿ�
    uint gcd;                          // �ִ�����
    uint res = 0;

    // ���� S �Է��ϸ鼭 ��ҵ� ���� �Ÿ����� GCD ���ϱ�
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

        // GCD ���ϱ�
        diff1 = max(param1 - param2, gcd);
        diff2 = min(param1 - param2, gcd);
        gcd = GCD(diff1, diff2);

        // ������ update
        param2 = param1;
    }

    // ���� GCD�� �̿��� ���� S�� �ִ� ������ �ּ� ���� ���ϱ�
    for (uint i = 1; i < ArraySize; i++)
        res += ((s[i] - s[i - 1]) / gcd) - 1;

    // ��� ���
    cout << res;

    return 0;
}