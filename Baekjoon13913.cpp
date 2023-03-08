/*
problem : start에서 end로 가는 방법 중 가장 짧은 시간을 구하고 경로를 출력해라.
input : start, end
output : start에서 end로 가는 최단 시간, 경로

idea
- start부터 시작하여 tree를 BFS로 탐색하면서 이전에 방문한 node를 저장한다.
- 최단 시간 출력
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isVisited[100001];            // 각 좌표의 방문 여부
int prevNode[100001];              // 탐색 시 각 node의 이전 탐색 node
vector<int> seq;                   // 방문 순서 seq

int BFS(int start, int end)
{
    queue<int> nextSearch;            // 다음에 탐색할 node를 저장 nextSearch
    int minimumLength=0;              // start에서 end로 가는 최단 시간
    
    // start 방문 처리 및 queue에 push
    isVisited[start] = true;
    nextSearch.push(start);
    
    // queue가 빌 때까지 반복
    while(!nextSearch.empty())
    {
        // 현재 queue의 크기만큼 반복해 현재 level 탐색
        int childNodeNum = nextSearch.size();
        
        for(int loopCount = 0; loopCount < childNodeNum; loopCount++)
        {
            // queue에서 좌표 하나 pop
            int current = nextSearch.front();
            nextSearch.pop();
            
            // end에 도착했다면 stack을 이용해 탐색 경로 저장
            if(current == end)
            {
                // 경로 저장
                int node = end;
                while(node != start)
                {
                    seq.push_back(node);
                    node = prevNode[node];
                }
                seq.push_back(start);
                
                return minimumLength;
            }
            
            // 3가지 방법의 결과 중 아직 방문하지 않았는 좌표를 queue에 push 및 방문 처리
            int method = current+1;
            if(method <= 100000 && !isVisited[method])
            {
                nextSearch.push(method);
                isVisited[method] = true;
                prevNode[method] = current;
            }
            method = current-1;
            if(method >= 0 && !isVisited[method])
            {
                nextSearch.push(method);
                isVisited[method] = true;
                prevNode[method] = current;
            }
            method = current*2;
            if(method <= 100000 && !isVisited[method])
            {
                nextSearch.push(method);
                isVisited[method] = true;
                prevNode[method] = current;
            }
        }
        
        // 최단 거리 증가
        minimumLength++;
    }
}

int main()
{
    // input 입력
    int start, end;
    cin >> start >> end;
    
    // BFS 탐색
    cout << BFS(start, end) << '\n';
    for(int i=seq.size()-1; i>=0; i--)
        cout << seq[i] << ' ';
    
    return 0;
}
