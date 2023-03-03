/*
problem : graph에서 cycle과 vertex 사이의 거리를 모두 출력해라.
input : graph
output : cycle과 vertex 사이의 거리

idea
- DFS 방식으로 graph을 탐색하여 cycle을 구한다.
- cycle에 속해 있으면 0을 저장한다
- cycle에 속하지 않으면 1부터 시작해 BFS 방식으로 탐색하여 cycle에 속하는 vertex 중 가장 가까운 거리를 구한다.
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[3001];    // graph
int vertexNum;              // vertex의 개수 vertexNum
bool isVisited[3001];       // 각 vertex의 방문 여부
bool isInCycle[3001];       // cycle에 속하는 vertex의 집합

bool isSearchCycle=false;   // cycle을 찾았는지 판단 isSearchCycle
int prevSearchVertex[3001]; // 이전에 방문했던 vertex의 모음(방문 기록) prevSearchVertex

int length[3001];           // cycle과 vertex 사이의 거리 length

void SearchCycleDFS(int currentVertex)
{
    // 현재 vertex 방문 표시
    isVisited[currentVertex] = true;
    
    // 현재 vertex와 연결된 vertex 탐색
    for(int i=0; i<graph[currentVertex].size(); i++)
    {
        // 만약 cycle을 찾았다면 탐색 종료
        if(isSearchCycle)
            return;
        
        // 다음에 탐색할 vertex
        int next = graph[currentVertex][i];
        
        // 이전에 방문 했으면서, 직전에 방문한 vertex가 아니라면 cycle을 찾았으므로 탐색 종료
        if(isVisited[next])
        {
            if(prevSearchVertex[currentVertex] != next)
            {
                // 현재 vertex를 cycle에 포함 및 cycle search 완료 설정
                isInCycle[currentVertex] = true;
                isSearchCycle = true;
            
                // cycle에 속하는 vertex 저장
                int tmp = currentVertex;
                while(tmp != next)
                {
                    isInCycle[prevSearchVertex[tmp]] = true;
                    tmp = prevSearchVertex[tmp];
                }
            
                // 팀색 종료
                return;
            } 
        }
        else
        {
            // 탐색 전 직전에 탐색한 vertex 설정
            prevSearchVertex[next] = currentVertex;
            SearchCycleDFS(next);
        }
    }
}

// cycle과 vertex 사이의 거리 구하기
void LengthToCycleBFS()
{
    queue<pair<int, int>> q;
    
    // cycle에 속하는 vertex를 queue에 모두 저장
    for(int i=1; i<=vertexNum; i++)
    {
        if(isInCycle[i])
        {
            isVisited[i] = true;
            q.push(make_pair(i, 0));
        }
    }
    
    while(!q.empty())
    {
        // queue에서 vertex 하나를 pop
        int currentVertex = q.front().first;
        int currentLength = q.front().second;
        q.pop();
        
        // 현재 vertex 방문 처리
        isVisited[currentVertex] = true;
        
        // 연결된 vertex 중 방문하지 않은 vertex들을 모두 queue에 push
        for(int i=0; i<graph[currentVertex].size(); i++)
        {
            int next = graph[currentVertex][i];
            
            if(isVisited[next])
                continue;
            
            length[next] = currentLength + 1;
            q.push(make_pair(next, currentLength + 1));
        }
    }
}

int main()
{
    // input 입력
    cin >> vertexNum;
    for(int i=0; i<vertexNum; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    // cycle 찾기
    SearchCycleDFS(1);
    
    // 방문 여부 초기화
    memset(isVisited, false, sizeof(isVisited));
    
    LengthToCycleBFS();
    
    // cycle과 vertex 사이의 거리 출력
    for(int i=1; i<=vertexNum; i++)
        cout << length[i] << ' ';
    
    return 0;
}
