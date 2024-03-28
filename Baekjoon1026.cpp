/*
problem : 길이가 n인 array 1과 array 2가 주어졌을 때, array 2의 순서를 바꾸지 않고, array 1의 순서를 바꿔 sum(array1[i] * array2[i])의 최소값을 구해라.
input : array 1, array 2
output : sum(array1[i] * array2[i])의 최소값

idea
- sum(array1[i] * array2[i])이 최소값이 되려면,
  array1 중 가장 큰 값에 array2 중 가장 작은 값을 곱해서 더하면 된다.
- array1을 오름차순으로, array2를 내림차순으로 정렬해 sum(array1[i] * array2[i])를 하면 최소값이 나온다.
*/
#include <iostream>
#include <algorithm>
#define BOUND 50
using namespace std;

int ArraySize;                // array의 길이
int arr1[BOUND];              // array1, array2
int arr2[BOUND];
int res;

int main()
{
    // array1, array2 입력
    cin >> ArraySize;
    for (int i = 0; i < ArraySize; i++)
        cin >> arr1[i];
    for (int i = 0; i < ArraySize; i++)
        cin >> arr2[i];

    // arr1을 오름차순으로, arr2를 내림차순으로 sort
    sort(arr1, arr1 + ArraySize);
    sort(arr2, arr2 + ArraySize, greater<int>());

    // sum(array1[i] * array2[i])을 구하고 결과값 출력
    for (int i = 0; i < ArraySize; i++)
        res += (arr1[i] * arr2[i]);

    cout << res;

    return 0;
}