/*
problem : graph을 DFS, BFS로 탐색한 결과를 출력해라.
input : graph, 탐색을 시작할 vertex
output : graph를 DFS, BFS로 탐색한 결과

idea : 재귀를 이용해 DFS 방식으로 탐색한 결과를 출력하고, queue를 이용해 BFS로 탐색한 결과를 출력한다.
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int vertexNumber;        // vertex의 개수 vertexNumber
int edgeNumber;          // edge의 개수 edgeNumber
int startVertex;         // 탐색을 시작할 vertex인 startVertex

bool graph[1001][1001];  // graph
bool isVisited[1001];    // 각 vertex의 방문 여부 isVisited

void DFS(int currentVertex)
{ 
    // 현재 vertex를 방문표시하고, 연결된 vertex 중 가장 작은 것부터 탐색한다.
    isVisited[currentVertex]=true;
    cout << currentVertex << ' ';
    for(int i=1; i<=vertexNumber; i++)
        // 아직 방문하지 않음 && edge로 연결되어 있음
        if(!isVisited[i] && graph[currentVertex][i])
            DFS(i);
}

void BFS(int startVertex)
{
    // queue 생성 및 탐색 시작 vertex를 queue에 push
    queue<int> searchSequence;
    searchSequence.push(startVertex);
    
    // 탐색 시작 vertex를 방문 표시 및 출력
    isVisited[startVertex]=true;
    cout << startVertex << ' ';
    
    // queue가 비어있을 때까지 반복
    while(!searchSequence.empty())
    {
        // queue에서 다음에 탐색할 vertex를 pop
        int currentVertex=searchSequence.front();
        searchSequence.pop();
        
        // 현재 vertex와 연결된 vertex를 모두 queue에 push
        for(int i=1; i<=vertexNumber; i++)
            // 아직 방문하지 않음 && edge로 연결되어 있음
            if(!isVisited[i] && graph[currentVertex][i])
            {
                // 조건에 만족하는 vertex 방문 표시 & 출력 & queue에 push
                isVisited[i]=true;
                cout << i << ' ';
                searchSequence.push(i);
            }
                
    }
}

int main()
{
    // input 입력
    cin >> vertexNumber >> edgeNumber >> startVertex;
    for(int i=0; i<edgeNumber; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = true;
        graph[v2][v1] = true;
    }
    
    // graph를 DFS로 탐색
    DFS(startVertex);
    cout << '\n';
    
    // isVisited 초기화
    memset(isVisited, false, sizeof(isVisited));
    
    // graph를 BFS로 탐색
    BFS(startVertex);
    cout << '\n';
    
    return 0;
}
