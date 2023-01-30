/*
problem : n개의 element를 가진 수열 array에서 중복을 허용하여 m개를 골라 만들 수 있는 수열을 모두 출력해라.
input : 수열 array, 자연수 m
output : 중복을 허용하여 m개를 골라 만들 수 있는 수열

idea : 수열 array를 increasing order로 sort한 후, DFS 방식으로 index 0번째부터 탐색을 시작하여 m개의 element를 고른다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int input[7];     // 수열 input == array
int length;       // 수열 array의 길이 length == n
int choose;       // 고를 element의 개수 == m
int output[7];    // 중복을 허용하여 m개를 골라 만든 수열 output

void DFS(int currentCount)
{
    // m개를 모두 골랐다면 수열 출력 후 function 종료
    if(currentCount == choose)
    {
        for(int i=0; i<choose; i++)
            cout << output[i] << ' ';
        cout << '\n';
        
        return;
    }
    
    // 현재 node의 모든 child node 방문
    for(int i=0; i<length; i++)
    {
        output[currentCount]=input[i];
        DFS(currentCount+1);
    }
}

int main()
{
    // 입출력 stream 동기화 해제 및 untie 작업
    // -> 알고리즘 속도 향상을 위해 사용
    // https://hegosumluxmundij.tistory.com/54 참고
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // input 입력
    cin >> length >> choose;
    for(int i=0; i<length; i++)
        cin >> input[i];
    
    // 주어진 수열을 increasing order로 sort
    sort(input, input+length);
    
    // DFS 방식으로 탐색하여 수열 만들기
    DFS(0);
    
    return 0;
}
