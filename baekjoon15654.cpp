/*
problem : n개의 정수를 가진 수열 array에서 중복없이 m개를 골라 만들 수 있는 수열을 사전 순으로 모두 출력해라.
input : 수열 array, 자연수 m
output : 수열 array에서 m개를 골라 만들 수 있는 수열들

idea : 수열 array를 increasing order로 sort한 후, DFS 방식으로 array를 탐색하여 수열을 만든다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int length;        // 수열 input의 길이 length == n
int choose;        // m == choose
int input[8];      // n개의 정수를 가진 수열 input
bool isVisited[8]; // input의 index 방문 여부 isVisited
int output[8];     // 수열 input에서 m개를 골라 만든 수열 output

void DFS(int currentCount)
{
    // m개를 모두 골랐다면 output 출력 후 function 종료
    if(currentCount == choose)
    {
        for(int i=0; i<choose; i++)
            cout << output[i] << ' ';
        cout << '\n';
        
        return;
    }
    
    // input의 index를 탐색하지 않았다면 index 탐색
    for(int i=0; i<length; i++)
    {
        if(!isVisited[i])
        {
            isVisited[i] = true;
            output[currentCount] = input[i];
            DFS(currentCount+1);
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
    
    // input를 increasing order로 sort
    sort(input, input+length);
    
    // DFS 방식으로 탐색하면서 m개의 element를 가진 output 만들기
    DFS(0);
    
    return 0;
}
