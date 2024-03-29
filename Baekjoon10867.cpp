/*
problem : n개의 수 중 중복되는 수를 모두 제거하고 오름차순으로 sort하고
input : n개의 수
output : 오름차순으로 정렬한 n개의 수

idea
- 입력을 받을 때, 이미 입력된 숫자라면 입력받지 않는다.
- 입력을 모두 받은 후 오름차순으로 sort
*/
#include <iostream>
#include <algorithm>
using namespace std;

int len;                        // 수열 S의 길이
int arr[100000];                // 수열 S
bool IsInput[2001];             // 현재 숫자가 입력받았는지 여부
                                // 0~1000 : 양수
                                // 1001 ~ 2000 : 음수

int main()
{
    int n, idx = 0, tmp;

    // 수열 S 입력
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> n;

        // 이미 입력된 숫자인지 검사
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

    // 수열 S의 길이 조정
    len = idx;

    // quick sort 진행
    sort(arr, arr + len);

    // 결과 출력
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';

    return 0;
}