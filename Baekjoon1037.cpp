/*
problem : 숫자 k의 약수들이 모두 주어졌을 때, k를 구해라.
input : n개의 약수들
output : n개의 약수들을 모두 가지고 있는 숫자 k

idea
- n개의 숫자를 오름차순으로 sort
- 첫번째 숫자와 마지막 숫자를 곱해 k를 구한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int cnt;                // 약수의 개수
    int input[50];          // 약수들

    // 주어진 숫자의 개수와 숫자들을 입력
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
        cin >> input[i];

    // 오름차순으로 sort
    sort(input, input + cnt);

    // 결과값 출력
    cout << input[0] * input[cnt - 1];

    return 0;
}