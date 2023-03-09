/*
problem : 3가지 방법을 이용해 1부터 end까지 가는 최단 시간을 구해라.
input : end
output : 1부터 end까지 가는 최단 시간

idea
- 1부터 시작하여 level이 시간을 나타내는 tree를 만든다.
- 각 경우에 대한 조건은 다음과 같다.
  1) 클립보드에 저장 : 화면에 이모티콘이 1개 이상 존재
  2) 화면에 붙여넣기 : 클립보드에 이모티콘이 1개 이상 존재
  3) 화면에 이모티콘 1개 감소 : 화면에 이모티콘이 1개 이상 존재
*/
#include <iostream>
#include <queue>
using namespace std;

int target;                        // 도착 지점 target
bool isCheckNode[2001][2001];      // 화면에 first개가 있고 클립보드에 second개가 있는 node 방문 여부

// 범위 계산
bool isCheckRange(int n1, int n2)
{
    if(n1 < 1 || n2 < 1 || n1 > 2000 || n2 > 2000)
        return false;
    return true;
}

int BFS()
{
    queue<pair<int, int>> nextSearch;        // 다음에 탐색할 node들 nextSearch
    int minimumTime=0;                       // end에 도착할 때 까지 걸린 시간 minimumTime
    
    // 1을 queue에 push 및 방문 처리
    nextSearch.push(make_pair(1, 0));
    isCheckNode[1][0] = true;
    
    // queue가 빌 때까지 반복
    while(!nextSearch.empty())
    {
        // queue의 사이즈만큼 반복
        int searchCount = nextSearch.size();
        
        for(int i=0; i<searchCount; i++)
        {
            // queue에서 좌표 하나 pop
            int currentNode = nextSearch.front().first;
            int currentClipboard = nextSearch.front().second;
            nextSearch.pop();
            
            // end에 도착하면 최소 시간 return
            if(currentNode == target)
                return minimumTime;
            
            int nextNode, nextClipboard;
            
            // 3가지 방법의 결과를 queue에 모두 push
            if(currentNode >= 1)
            {
                // 클립보드에 복사 연산
                nextNode = currentNode;
                nextClipboard = currentNode;
                if(isCheckRange(nextNode, nextClipboard) && !isCheckNode[nextNode][nextClipboard])
                {
                    nextSearch.push(make_pair(nextNode, nextClipboard));
                    isCheckNode[nextNode][nextClipboard] = true;
                }
                
                // 화면에 이모티콘 1개 삭제 연산
                nextNode = currentNode-1;
                nextClipboard = currentClipboard;
                if(isCheckRange(nextNode, nextClipboard) && !isCheckNode[nextNode][nextClipboard])
                {
                    nextSearch.push(make_pair(nextNode, nextClipboard));
                    isCheckNode[nextNode][nextClipboard] = true;
                }
            }

            // 화면에 붙여넣기 연산
            nextNode = currentNode+currentClipboard;
            nextClipboard = currentClipboard;
            if(currentClipboard >= 1 && isCheckRange(nextNode, nextClipboard) && !isCheckNode[nextNode][nextClipboard])
            {
                nextSearch.push(make_pair(nextNode, nextClipboard));
                isCheckNode[nextNode][nextClipboard] = true;
            }   
        }
        
        // 시간 증가
        minimumTime++;
    }
}

int main()
{
    // input 입력
    cin >> target;
    
    // 결과 출력
    cout << BFS();
    
    return 0;
}
