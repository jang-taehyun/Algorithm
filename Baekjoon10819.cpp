/*
problem : n개의 element를 가진 수열 array에서 |arr[0]-arr[1]| + |arr[1]-arr[2]| + ... + |arr[n-2]-arr[n-1]|의 최대값을 구해라.
input : 수열 array
output : |arr[0]-arr[1]| + |arr[1]-arr[2]| + ... + |arr[n-2]-arr[n-1]|의 최대값

idea : 수열 array를 DFS 방식으로 탐색하면서 중복없이 n개를 뽑아서 수열을 만든후 |arr[0]-arr[1]| + |arr[1]-arr[2]| + ... + |arr[n-2]-arr[n-1]|을 계산한다.
만약 계산 결과가 지금 까지 최대값보다 크다면 최대값을 바꾼다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int length;           // 수열 array의 길이 length == n
int input[8];         // n개의 element를 가진 수열 input == array
int res;              // 최대값
int output[8];        // 수열 array에서 n개를 뽑아 만든 수열 output
bool isVisited[8];    // 수열 array의 element의 방문 여부 isVisited

void DFS(int currentCount)
{
    // n개를 모두 뽑았다면 |arr[0]-arr[1]| + |arr[1]-arr[2]| + ... + |arr[n-2]-arr[n-1]|를 계산하고 탐색을 종료한다.
    // 만약 현재까지 얻은 최대값보다 크다면 업데이트한다.
    if(currentCount == length)
    {
        int sum=0;
        for(int i=0; i<length-1; i++)
            sum += abs(output[i] - output[i+1]);
        
        res = sum > res ? sum : res;
        return;
    }
    
    // DFS 방식으로 수열 array에서 중복없이 n개를 뽑아 새로운 수열을 만든다.
    for(int i=0; i<length; i++)
    {
        if(!isVisited[i])
        {
            isVisited[i]=true;
            output[currentCount]=input[i];
            DFS(currentCount+1);
            isVisited[i]=false;
        }
    }
}

int main()
{
    // input 입력
    cin >> length;
    for(int i=0; i<length; i++)
        cin >> input[i];
    
    // DFS 방식으로 탐색하여 중복없이 n개를 뽑아 수열을 만든 후, |arr[0]-arr[1]| + |arr[1]-arr[2]| + ... + |arr[n-2]-arr[n-1]|를 계산한다.
    DFS(0);
    
    // 결과 출력
    cout << res;
    
    return 0;
}
