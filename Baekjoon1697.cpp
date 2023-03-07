/*
problem : 시작점 x에서 도착점 y까지 가는 최단 시간을 구해라.
input : 시작점 x, 도착점 y
output : 시작점 x에서 도착점 y까지 가는 최단 시간

idea
- 시작점 x에서부터 시작하여 x-1, x+1, 2*x로 가는 방법을 BFS로 탐색한다.
- 도착점 y에 가장 먼저 도착한 level이 최단 시간
*/
#include <iostream>
#include <queue>
using namespace std;

bool isVisited[100001];                   // 각 지점의 방문 여부 isVisited

int BFS(int start, int end)
{
    queue<int> nextSearch;                // 다음에 탐색할 지점의 집합 nextSearch
    int shortestTime=0;                   // 최단 시간 shortestTime
    
    // 시작점을 queue에 push 및 방문 표시
    nextSearch.push(start);
    isVisited[start] = true;
    
    // queue가 빌 때까지 반복
    while(!nextSearch.empty())
    {
        int loopCount = nextSearch.size();
        
        // queue의 크기 만큼 반복
        for(int count=0; count<loopCount; count++)
        {
            // queue에서 좌표 하나를 pop
            int current = nextSearch.front();
            nextSearch.pop();
            
            // 만약 도착점이 있다면 얻어진 최단 시간 return
            if(current == end)
                return shortestTime;
            
            // 3가지 방법의 결과를 중 아직 방문하지 않는 지점을 모두 push 및 방문 처리
            int method = current + 1;
            if(method <= 100001 && !isVisited[method])
            {
                nextSearch.push(method);
                isVisited[method] = true;
            }
            method = current - 1;
            if(method >= 0 && !isVisited[method])
            {
                nextSearch.push(method);
                isVisited[method]=true;
            }
            method = current * 2;
            if(method <= 100001 && !isVisited[method])
            {
                nextSearch.push(method);
                isVisited[method] = true;;
            }
        }
        
        // 최단 시간 증가
        shortestTime++;
    }
}

int main()
{    
    int start, end;        // 시작점 start, 도착점 end
    cin >> start >> end;
    
    // 결과 출력
    cout << BFS(start, end);

    return 0;
}
