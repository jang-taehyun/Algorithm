/*
problem : graph가 bipartite graph인지 판단해라.
input : graph
output : bipartite graph이면 YES를 출력, 아니라면 NO를 출력

bipartite graph(이분 그래프) : graph 내 모든 인접한 vertex가 서로 다른 색으로 칠해진 graph

idea : graph내 vertex를 방문하면 인접한 vertex는 다른 색으로 칠해준 후, 탐색이 모두 끝나면 graph 내 모든 vertex를 검사하면서 인접한 vertex와 다른 색인지 확인한다.
모두 다르다면 YES, 아니면 NO를 출력한다.
*/
#include <iostream>
#include <vector>
#include <cstring>

// vertex별 색깔
#define NONE 0
#define BLACK 1
#define RED 2

using namespace std;

vector<int> graph[20001];            // graph
int vertexColor[20001];              // 각 vertex마다의 색깔 vertexColor
int vertexNumber;                    // vertex의 개수 vertexNumber
int edgeNumber;                      // edge의 개수 edgeNumber

// DFS 방식(재귀)으로 탐색
void DFS(int currentVertex)
{
    // 아직 방문하지 않는 vertex는 RED로 칠한다.
    if(!vertexColor[currentVertex])
        vertexColor[currentVertex]=RED;
    
    // 현재 vertex와 연결된 vertex 중 방문하지 않는 vertex를 방문한다.
    for(int i=0; i<graph[currentVertex].size(); i++)
    {
        if(!vertexColor[graph[currentVertex][i]])
        {
            // 방문할 vertex를 현재 vertex와 다른 색깔로 칠한다.
            int color = vertexColor[currentVertex] == RED ? BLACK : RED;
            vertexColor[graph[currentVertex][i]] = color;
            
            // 방문할 vertex 탐색
            DFS(graph[currentVertex][i]);
        }
    }
}

// bipartite graph인지 확인
bool isBipartite()
{
    for(int vertex=1; vertex<=vertexNumber; vertex++)
        for(int adj=0; adj<graph[vertex].size(); adj++)
            // 만약 현재 vertex와 인접한 vertex의 색깔이 같다면 bipartite graph가 아니다.
            if(vertexColor[vertex] == vertexColor[graph[vertex][adj]])
                return false;
    
    return true;
}

int main()
{   
    // testcase 입력
    int testcase;
    cin >> testcase;
    
    while(testcase--)
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
        
        // DFS 방식으로 색깔을 칠해가면서 graph 탐색
        for(int i=1; i<=vertexNumber; i++)
            if(!vertexColor[i])
                DFS(i);
        
        // bipartite graph인지 확인
        if(isBipartite())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        
        // 초기화
        memset(vertexColor, 0, sizeof(vertexColor));
        for(int i=0; i<20001; i++)
            graph[i].erase(graph[i].begin(), graph[i].end());
    }
    
    return 0;
}
