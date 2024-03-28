/*
problem : ���̰� n�� array 1�� array 2�� �־����� ��, array 2�� ������ �ٲ��� �ʰ�, array 1�� ������ �ٲ� sum(array1[i] * array2[i])�� �ּҰ��� ���ض�.
input : array 1, array 2
output : sum(array1[i] * array2[i])�� �ּҰ�

idea
- sum(array1[i] * array2[i])�� �ּҰ��� �Ƿ���,
  array1 �� ���� ū ���� array2 �� ���� ���� ���� ���ؼ� ���ϸ� �ȴ�.
- array1�� ������������, array2�� ������������ ������ sum(array1[i] * array2[i])�� �ϸ� �ּҰ��� ���´�.
*/
#include <iostream>
#include <algorithm>
#define BOUND 50
using namespace std;

int ArraySize;                // array�� ����
int arr1[BOUND];              // array1, array2
int arr2[BOUND];
int res;

int main()
{
    // array1, array2 �Է�
    cin >> ArraySize;
    for (int i = 0; i < ArraySize; i++)
        cin >> arr1[i];
    for (int i = 0; i < ArraySize; i++)
        cin >> arr2[i];

    // arr1�� ������������, arr2�� ������������ sort
    sort(arr1, arr1 + ArraySize);
    sort(arr2, arr2 + ArraySize, greater<int>());

    // sum(array1[i] * array2[i])�� ���ϰ� ����� ���
    for (int i = 0; i < ArraySize; i++)
        res += (arr1[i] * arr2[i]);

    cout << res;

    return 0;
}