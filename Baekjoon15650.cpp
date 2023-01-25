/*
problem : 1부터 n까지 자연수 중 중복없이 m개를 골라 수열을 만들 때, 오름차순으로 이루어진 수열을 모두 출력해라.
input : 마지막 숫자 n, 고를 숫자의 개수 m
output : 1부터 n까지 자연수 중 m개를 골라 수열을 만들 때, 오름차순으로 이루어진 수열들

idea : DFS 방식으로 1부터 시작해 오름차순을 이루는 모든 수열을 출력
*/
#include <iostream>
using namespace std;

int output[8];        // 수열 output
bool isVisited[9];    // 숫자의 방문 여부 isVisited
int n;                // 마지막 숫자 n
int choose;           // 고를 숫자의 개수 m

void DFS(int currentCount, int currentNumber)
{
    // 고를 숫자의 개수와 같다면, 수열 출력 후 function 종료
    if(currentCount == choose)
    {
        for(int i=0; i<choose; i++)
            cout << output[i] << ' ';
        cout << '\n';
        return;
    }
    
    // 현재 숫자보다 큰 숫자들 중에서 골라 DFS 방식으로 탐색
    for(int i=currentNumber; i<=n; i++)
    {
        // 만약 숫자 i를 방문하지 않았다면
        if(!isVisited[i])
        {
            // 숫자 i를 output에 넣고 다음 것 방문
            isVisited[i]=true;
            output[currentCount]=i;
            DFS(currentCount+1, i);
            // 방문 후 다시 원상 복구
            isVisited[i]=false;
        }
    }
}

int main()
{
    cin >> n >> choose;
    DFS(0, 1);
    
    return 0;
}
