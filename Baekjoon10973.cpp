/*
problem : 1부터 n까지 숫자를 가지고 만들 수 있는 수열 중, 수열 array보다 이전에 만들어지는 수열을 구해라
input : 수열 array, 숫자의 범위 n
output : 수열 array보다 이전에 만들어지는 수열

idea
1) 수열 array를 뒤에서부터 탐색하여 increasing order로 정렬된 부분 중 시작 부분(start)을 찾는다.
   - 시작 부분(start)이 0번째 index인 경우, -1을 출력하고 함수를 종료한다.
2) 수열 array를 뒤에서부터 탐색하여 시작 부분(start)의 이전 숫자보다 작은 숫자(smaller)를 찾는다.
3) 시작 부분(start)의 이전 숫자와 작은 숫자(smaller)의 위치를 바꾼다.
4) 시작 부분(start)부터 수열 array의 끝까지 decreasing order로 정렬한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

void Swap(int index1, int index2, int* arr)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int main()
{
    // input으로 주어지는 수열 array인 input
    int input[10000];
    // 숫자의 범위 range == n
    int range=0;
    // increasing order로 정렬된 부분의 시작 index인 startIndex
    int startIndex=0;
    // increasing order로 정렬된 부분에서 startIndex-1 번째 숫자보다 작은 숫자 smallerIndex
    int smallerIndex=0;
    
    // input 입력
    cin >> range;
    for(int i=0; i<range; i++)
        cin >> input[i];
    
    // 수열 array를 뒤에서부터 탐색하여 increasing order로 정렬된 부분의 시작(startIndex)을 찾는다.
    startIndex=range;
    while((--startIndex)>0 && input[startIndex-1] < input[startIndex]);
    if(!startIndex)
    {
        cout << -1;
        return 0;
    }
    
    // 수열 array를 뒤에서부터 탐색하여 increasing order로 정렬된 부분 중 startIndex-1 번째 숫자보다 작은 숫자(smallerIndex)를 찾는다.
    smallerIndex=range;
    while((--smallerIndex)>startIndex-1 && input[startIndex-1] < input[smallerIndex]);
    
    // startIndex-1 번째 숫자와 smallerIndex 번째 숫자의 위치 교환
    Swap(startIndex-1, smallerIndex, input);
    
    // startIndex부터 수열 array의 끝까지 decreasing order로 정렬
    sort(input+startIndex, input+range, greater<int>());
    
    // 수열 출력
    for(int i=0; i<range; i++)
        cout << input[i] << ' ';
    cout << '\n';
    
    return 0;
}
