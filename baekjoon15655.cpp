/*
problem : n개의 element를 가진 수열 array에서 중복없이 m개를 골라 만든 수열 중 오름차순으로 정렬된 수열을 모두 출력해라.
input : 수열 array, 자연수 m
output : array에서 중복없이 m개를 골라 만들어진 수열 중 오름차순으로 정렬된 수열

idea : 수열 array를 오름차순으로 정렬 후, index 0번째부터 시작하여 DFS 방식으로 탐색하면서 m개를 골라 수열을 만든다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int length;            // 수열 array의 길이 length == n
int choose;           // 선택할 element의 개수 choose == m
int input[8];          // 주어진 수열 input == array
bool isVisited[8];     // index 방문 여부 확인
int output[8];         // 만들어진 수열 output

void DFS(int currentCount, int startIndex)
{
    // m개를 모두 골랐다면 출력 후 function 종료
    if(currentCount == choose)
    {
        for(int i=0; i<choose; i++)
            cout << output[i] << ' ';
        cout << '\n';
        
        return;
    }
    
    // 현재 node의 child를 DFS 방식으로 탐색
    for(int i=startIndex; i<length; i++)
    {
        if(!isVisited[i])
        {
            isVisited[i] = true;
            output[currentCount] = input[i];
            DFS(currentCount+1, i);
            isVisited[i] = false;
        }
    }
}

int main()
{
    // input 입력
    cin >> length >> choose;
    for(int i=0; i<length; i++)
        cin >> input[i];
    
    // 수열을 increasing order로 sort
    sort(input, input+length);
    
    // DFS 방식으로 탐색하면서 m개의 element 고르기
    DFS(0, 0);
    
    return 0;
}
