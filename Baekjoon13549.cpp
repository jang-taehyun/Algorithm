/*
problem : 시작점 x에서 도착점 y까지 가는 방법 중 최단 시간을 구해라.
input : 시작점 x, 도착점 y
output : 시작점 x에서 도착점 y까지 가는 방법 중 최단 시간

idea
- 시작점 x에서부터 시작하여 각 방법으로 만들어진 경우들을 BFS 방식으로 탐색한다.
- 경우 3가지 : x+1, x-1, x*2
  -> 이때 x*2는 0초의 시간이 걸리므로 가장 먼저 탐색한다.
- 만약 100,000을 넘어가거나 0 미만이라면 탐색하지 않는다.
- 탐색하면서 각 지점에 도착할 때까지 걸리는 (최소 시간+1)을 저장한다.
  -> +1을 하는 이유는 방문 처리를 위해
*/
#include <iostream>
#include <deque>
using namespace std;

int startNode, endNode;               // 시작점, 도착점 start, end
int ArriveShortestTime[100001];       // 각 지점까지 가는 최단 시간 ArriveShortestTime

// 범위 검사
bool CheckRange(int n)
{
    if(n < 0 || n > 100000)
        return false;
    return true;
}

// promising 검사
bool isPromising(int n)
{
    if(!CheckRange(n) || ArriveShortestTime[n])
        return false;
    return true;
}

int BFS()
{
    deque<int> nextSearch;     // 다음에 탐색할 node의 모음 nextSearch
    
    // deque에 start를 넣고 방문 처리
    nextSearch.push_back(startNode);
    ArriveShortestTime[startNode] = 1;
    
    // deque이 빌 때까지 반복
    while(!nextSearch.empty())
    {
        // deque 좌표 하나 pop
        int current = nextSearch.front();
        int time = ArriveShortestTime[current];
        nextSearch.pop_front();
            
        // 도착점에 도달하면 시간 return
        if(current == endNode)
            return time-1;
            
        // 3가지 연산의 결과를 deque에 push 및 방문 처리
        if(isPromising(current*2))
        {
            nextSearch.push_front(current*2);
            ArriveShortestTime[current*2] = time;
        }
        if(isPromising(current+1))
        {
            nextSearch.push_back(current+1);
            ArriveShortestTime[current+1] = time+1;
        }   
        if(isPromising(current-1))
        {
            nextSearch.push_back(current-1);
            ArriveShortestTime[current-1] = time+1;
        }
    }
}

int main()
{
    // input 입력
    cin >> startNode >> endNode;
    
    // 결과 출력
    cout << BFS();
    
    return 0;
}
