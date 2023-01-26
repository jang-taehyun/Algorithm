/*
problem : 1부터 n까지 자연수 중 중복을 허용하여 m개를 골라 만든 수열을 모두 출력해라.
input : 자연수 n과 m
output : 1부터 n까지 자연수 중 중복을 허용하여 m개를 골라 만든 수열

idea : 1부터 n까지 자연수를 DFS 방식으로 탐색하여 m개를 고른 후 수열을 출력한다.
*/
#include <iostream>
using namespace std;

int output[7];  // 수열 output
int bound;      // n == bound
int length;     // m == length

void DFS(int currentCount)
{
    // m개를 모두 골랐다면, 수열을 모두 출력한 후 function 종료
    if(currentCount == length)
    {
        for(int i=0; i<length; i++)
            cout << output[i] << ' ';
        cout << '\n';
        
        return;
    }
    
    // 1부터 n까지 숫자들을 모두 방문
    for(int i=1; i<=bound; i++)
    {
        // 현재 수열의 index에 숫자 i를 넣는다.
        output[currentCount]=i;
        // (currentCount+1)번째 index에 들어갈 숫자 탐색
        DFS(currentCount+1);
    }
}

int main()
{
    cin >> bound >> length;
    DFS(0);
    
    return 0;
}
