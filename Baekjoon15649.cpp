/*
problem : 1부터 n까지 자연수 중에서 중복 없이 m개를 고른 수열을 모두 출력하라.
input : 자연수 n, m
output : 1부터 n까지 자연수 중에서 중복 없이 m개를 고른 수열들

idea : 1부터 시작해 DFS 방식 수열을 만든 후 출력한다.
*/
#include <iostream>
#include <cstring>
using namespace std;

// currentIndex : 현재 만들어진 수열의 길이
// end == m
// output : 수열
void DFS(int currentIndex, const int end, const int n, int* output, bool* isVisited)
{
    // m개를 모두 골랐을 때, 수열 출력 후 function 종료
    if(currentIndex == end)
    {
        for(int i=0; i<end; i++)
            cout << output[i] << ' ';
        cout << '\n';
        return;
    }
    
    // 다른 숫자 방문
    for(int i=1; i<=n; i++)
    {
        // 만약 숫자 i를 방문하지 않았다면
        if(!isVisited[i])
        {
            // 방문 표시
            isVisited[i] = true;
            // 숫자 i를 output에 집어넣기
            output[currentIndex] = i;
            // DFS 방식으로 다시 탐색
            DFS(currentIndex+1, end, n, output, isVisited);
            // 방문 표시 초기화
            isVisited[i] = false;
        }
    }

        
}

int main()
{
    // 자연수 n, m
    int n=0, m=0;
    // 출력되는 수열 output
    int output[8];
    // 방문여부 확인 isVisited
    bool isVisited[9];
    
    // output, isVisited 초기화
    memset(output, 0, sizeof(output));
    memset(isVisited, false, sizeof(isVisited));
    
    // 자연수 n, m 입력
    cin >> n >> m;
    
    // root가 1인 tree부터 시작해 n인 tree까지 DFS 방식으로 탐색
    DFS(0, m, n, output, isVisited);
    
    return 0;
}
