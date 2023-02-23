/*
problem : undirected graph에서 connected componenet의 개수를 구해라.
input : undirected graph
output : connected component의 개수

idea : undirected graph를 DFS 방식으로 탐색 하여 connected component의 개수를 구한다.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1001];        // undirected graph
int vertexNumber;               // vertex의 개수 vertexNumber
int edgeNumber;                 // edge의 개수 edgeNumber
bool isVisited[1001];           // vertex의 방문 여부 isVisited

int connectedComponent=0;       // connectedComponent의 개수 connectedComponent

void DFS(int currentVertex)
{
    // 현재 vertex를 방문 처리
    isVisited[currentVertex]=true;
    
    // 현재 vertex와 연결된 vertex 중 방문하지 않는 vertex 방문
    for(int vertexIndex=0; vertexIndex<graph[currentVertex].size(); vertexIndex++)
        if(!isVisited[graph[currentVertex][vertexIndex]])
            DFS(graph[currentVertex][vertexIndex]);
}

int main()
{
    // input 입력
    cin >> vertexNumber >> edgeNumber;
    for(int i=0; i<edgeNumber; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    // undirected graph의 모든 vertex를 시작점으로 하여 connected componenet의 개수를 구한다.
    for(int i=1; i<=vertexNumber; i++)
    {
        if(!isVisited[i])
        {
            connectedComponent++;
            DFS(i);
        }
    }
    
    // 결과 출력
    cout << connectedComponent;
    
    return 0;
}
