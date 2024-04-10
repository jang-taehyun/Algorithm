/*
problem : ���� S�� �־����� ��, �����ؼ� 3�� ���� ���� �����鼭 ������ ��Ҹ� ��� ���� �ִ밪�� ���ض�.
input : ���� S
output : �����ؼ� 3���� ���� ���� �����鼭 ������ ��Ҹ� �� ���� ���� �ִ밪

idea
- dp[i] : i��° ��Ҹ� ����� ��, ���� �ִ밪
  dp[i] = max(dp[i-3]+s[i-1], dp[i-2]) + s[i];
*/
#include <iostream>
#include <algorithm>
using namespace std;

int input[300];            // ���� S
int dp[300];               // dp

int main()
{
    int ArrayLength;           // ���� S�� ���� 

    // ���� S �Է�
    cin >> ArrayLength;
    for (int i = 0; i < ArrayLength; i++)
        cin >> input[i];

    // dp�� �ʱⰪ �Է�
    dp[0] = input[0];
    dp[1] = max(input[0], 0) + input[1];
    dp[2] = max(input[0], input[1]) + input[2];

    // ������ ���̸�ŭ dp�� ����
    for (int i = 3; i < ArrayLength; i++)
        dp[i] = max(dp[i - 3] + input[i - 1], dp[i - 2]) + input[i];

    // �ִ밪 ���
    cout << dp[ArrayLength - 1];

    return 0;
}