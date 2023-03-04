/*
problem : graph을 BFS 방식으로 올바르게 탐색하면 1을 아니라면 0을 출력해라.
input : graph, BFS 탐색 순서
output : 올바르게 탐색하였다면 1을, 아니라면 0을 출력해라.

idea
- input으로 주어지는 BFS 탐색 순서를 이용해, 각 vertex마다 연결된 vertex를 재정렬한다.
- vertex 1부터 시작하여 BFS로 Graph를 탐색하면서 input으로 주어진 탐색 순서를 확인한다. 
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[100001];        // graph
int vertexNum;                    // vertex의 개수 vertexNum
int searchPriority[100001];       // input으로 주어지는 vertex의 탐색 순서 searchPriority(sort에 사용)
int searchSeq_input[100001];      // input으로 주어지는 vertex의 탐색 순서 searchSeq_input(탐색 순서 비교에 사용)
int searchSeq_output[100001];     // BFS 탐색 순서
bool isVisited[100001];           // 각 vertex의 방문 여부 isVisited
bool isRight=false;               // input과 실제 탐색 순서를 비교한 결과 isRight

// 탐색 순서 판별
bool IsPriority(int idx1, int idx2) { return searchPriority[idx1] < searchPriority[idx2]; }

// 왼쪽에 위치한 vertex부터 탐색하는 방법
bool BFS()
{
    // vertex 1 방문 표시 및 queue 생성 후 push
    isVisited[1] = true;
    queue<int> nextSearch;
    nextSearch.push(1);
    
    // 탐색 순서 searchIndex 생성 및 searchSeq_output에 vertex 1 저장
    int searchIndex=0;
    searchSeq_output[searchIndex] = 1;
    
    // queue가 비어있을 때까지 반복
    while(!nextSearch.empty())
    {
        // queue에서 vertex 1개를 pop
        int currentVertex = nextSearch.front();
        nextSearch.pop();
        
        for(int i=0; i<graph[currentVertex].size(); i++)
        {
            int next = graph[currentVertex][i];
            
            if(!isVisited[next])
            {
                isVisited[next] = true;
                nextSearch.push(next);
                searchIndex++;
                searchSeq_output[searchIndex] = next;
            }
        }
    }
    
    // 탐색을 완료했다면 input과 비교
    for(int i=0; i<vertexNum; i++)
        // 같지 않다면 함수 종료
        if(searchSeq_input[i] != searchSeq_output[i])
            return false;
    return true;
}

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
        
        searchPriority[tmp] = i;
        searchSeq_input[i-1] = tmp;
    }
    
    // 탐색 순서에 따라 vertex마다 연결된 vertex들을 sort
    for(int i=1; i<=vertexNum; i++)
        sort(graph[i].begin(), graph[i].end(), IsPriority);
    
    // 결과 출력
    cout << BFS();
    
    return 0;
}
