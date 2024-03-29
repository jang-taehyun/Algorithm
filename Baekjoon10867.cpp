/*
problem : n���� �� �� �ߺ��Ǵ� ���� ��� �����ϰ� ������������ sort�ϰ�
input : n���� ��
output : ������������ ������ n���� ��

idea
- �Է��� ���� ��, �̹� �Էµ� ���ڶ�� �Է¹��� �ʴ´�.
- �Է��� ��� ���� �� ������������ sort
*/
#include <iostream>
#include <algorithm>
using namespace std;

int len;                        // ���� S�� ����
int arr[100000];                // ���� S
bool IsInput[2001];             // ���� ���ڰ� �Է¹޾Ҵ��� ����
                                // 0~1000 : ���
                                // 1001 ~ 2000 : ����

int main()
{
    int n, idx = 0, tmp;

    // ���� S �Է�
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> n;

        // �̹� �Էµ� �������� �˻�
        if (n < 0)
            tmp = (n * -1) + 1000;
        else
            tmp = n;

        if (!IsInput[tmp])
        {
            IsInput[tmp] = true;
            arr[idx] = n;
            idx++;
        }
    }

    // ���� S�� ���� ����
    len = idx;

    // quick sort ����
    sort(arr, arr + len);

    // ��� ���
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';

    return 0;
}