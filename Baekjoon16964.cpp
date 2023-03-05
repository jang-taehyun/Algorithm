/*
problem : graph를 DFS 방식으로 탐색한 순서가 올바르면 1을, 아니라면 0을 출력해라.
input : graph, DFS 방식으로 탐색한 순서
output : DFS 방식으로 탐색한 순서가 올바르면 1을, 아니라면 0을 출력해라.

idea
- DFS 방식으로 탐색한 순서를 입력받은 후 탐색 순서에 따라 연결된 vertex 들을 sort한다.
- DFS 방식으로 graph을 탐색한 후, input과 같은지 확인한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[100001];        // graph
int vertexNum;                    // vertex의 개수 vertexNum
int searchPriority[100001];       // 탐색 우선 순위 searchPriority(sort에 사용)
int searchSeq_input[100001];      // input으로 주어진 탐색 순서 searchSeq_input
int searchSeq_output[100001];     // 실제 DFS 탐색 순서 searchSeq_output
bool isVisited[100001];           // vertex 방문 여부 isVisited
int currentCount=-1;              // 방문한 vertex의 개수 currentCount

bool IsPriority(int idx1, int idx2) { return searchPriority[idx1] < searchPriority[idx2]; }

void DFS(int currentVertex);

int main()
{
    // input 입력
    cin >> vertexNum;
    for(int i=0; i<vertexNum-1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i=1; i<=vertexNum; i++)
    {
        int tmp;
        cin >> tmp;
        
        searchSeq_input[i-1] = tmp;
        searchPriority[tmp] = i;
    }
    
    // 탐색 순서에 따라 vertex와 연결된 vertex들을 sort
    for(int i=1; i<=vertexNum; i++)
        sort(graph[i].begin(), graph[i].end(), IsPriority);
    
    // 실제 DFS 탐색
    DFS(1);
    
    // 탐색 결과 비교 후 결과 출력
    bool result = true;
    for(int i=0; i<vertexNum; i++)
    {
        if(searchSeq_input[i] != searchSeq_output[i])
        {
            result = false;
            break;
        }
    }
    cout << result;
    
    return 0;
}

void DFS(int currentVertex)
{
    // 현재 vertex를 이미 방문했다면 탐색 종료
    if(isVisited[currentVertex])
        return;
    
    // 현재 vertex 방문 표시 및 방문 순서 저장
    isVisited[currentVertex] = true;
    searchSeq_output[++currentCount] = currentVertex;
    
    // 현재 vertex와 연결된 vertex 중 아직 방문하지 않는 vertex 모두 방문
    for(int i=0; i<graph[currentVertex].size(); i++)
    {
        int next = graph[currentVertex][i];
        if(!isVisited[next])
            DFS(next);
    }
}
