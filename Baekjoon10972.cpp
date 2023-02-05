/*
problem : 1부터 n까지 수를 이용해 수열을 만든 후 사전 순으로 정렬할 때, 수열 array의 다음 수열을 구해라. 없다면 -1을 출력해라.
input : 숫자의 범위 n, 수열 array
output : 사전 순으로 정렬했을 때 수열 array 다음으로 오는 수열

idea
- 뒤에서부터 탐색하여 내림차순이 시작하는 지점을 찾는다.
  - 이때 수열의 첫부분까지 도달했다면 마지막으로 만들어지는 수열이므로 -1을 출력하고 끝낸다.
- 내림차순의 첫 숫자(index 번째 숫자)보다 앞에 있는 숫자(index-1 번째 숫자)보다 처음으로 큰 숫자를 찾고 자리를 바꿔준다.
- 내림자순의 첫 숫자부터 마지막 숫자까지 자리를 모두 바꿔준다.
*/
#include <iostream>
using namespace std;

int length;               // 숫자의 범위 length == n
int input[10000];         // input으로 주어지는 수열 input == array

void Swap(int i1, int i2)
{
    int temp = input[i1];
    input[i1] = input[i2];
    input[i2] = temp;
}

bool Next_Permutation()
{
    // 내림차순의 시작 부분 찾기
    int startIndex = length - 1;
    while (startIndex > 0 && input[startIndex - 1] >= input[startIndex])
        startIndex--;
    if (startIndex <= 0)
        return false;

    // 내림차순의 시작보다 앞에 있는 숫자보다 처음으로 큰 숫자 찾아서 swap
    int Biggerindex = length - 1;
    while (input[startIndex - 1] >= input[Biggerindex])
        Biggerindex--;
    Swap(startIndex - 1, Biggerindex);

    // 내림차순의 시작부터 끝까지 자리를 모두 바꿔준다.
    int endIndex = length - 1;
    while (startIndex < endIndex)
        Swap(startIndex++, endIndex--);
    return true;
}

int main()
{
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    if (!Next_Permutation())
        cout << -1;
    else
        for (int i = 0; i < length; i++)
            cout << input[i] << ' ';

    return 0;
}