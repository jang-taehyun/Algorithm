/*
problem : n개의 도시를 모두 방문한 후 다시 처음 지점으로 되돌아오는 경로 중 edge의 가중치가 최소가 경로를 구해라.
input : 도시의 개수 n, 각 도시들끼리 연결된 edge의 가중치 W
output : n개의 도시를 모두 방문한 후 다시 처음 지점으로 되돌아오는 경로 중 edge의 가중치가 최소가 경로의 가중치의 합

idea : 1부터 n까지 DFS 방식으로 수열을 만든 후 가중치의 합을 구한다. 이때 현재 구해진 가중치의 합이 지금까지 구해진 가중치의 합보다 크다면 업데이트 한다.
- non-promising : 현재 고른 element는 이미 방문했다. && 이전에 골랐던 element와 현재 고른 element 사이의 가중치가 0이다.
*/
#include <iostream>
using namespace std;

int cityNumber;             // 도시의 개수 cityNumber
int W[10][10];              // 각 element들이 연결된 edge의 weight인 W
int visitedSequence[10];    // 방문할 순서 visitedSequence
bool isVisited[10];         // 각 element의 방문 여부
int minimumWeight=99999999;  // n개의 도시를 모두 방문한 후 다시 처음 지점으로 되돌아오는 경로 중 edge의 가중치가 최소가 경로의 가중치의 합 minimumWeight

void DFS(int currentCount)
{
    // n개의 도시의 방문 순서를 결정했다면 가중치들의 합을 구한다.
    // 이때, 마지막으로 방문하는 도시와 첫 번째로 방문하는 도시 사이에 edge가 없다면 계산하지 않는다.(non-promising 조건)
    if(currentCount == cityNumber)
    {
        if(!W[visitedSequence[cityNumber-1]][visitedSequence[0]])
            return;
        
        int sum=0;
        for(int i=1; i<cityNumber; i++)
            sum += W[visitedSequence[i-1]][visitedSequence[i]];
        sum += W[visitedSequence[cityNumber-1]][visitedSequence[0]];
        
        minimumWeight = sum < minimumWeight ? sum : minimumWeight;
        
        return;
    }
    
    // DFS 방식으로 각 element의 방문 순서를 정한다.
    for(int i=0; i<cityNumber; i++)
    {
        // non-promising : 현재 고른 element는 이미 방문 했다. && 이전에 골랐던 element와 현재 고른 element 사이의 weight가 0이다.
        if(!isVisited[i] && W[visitedSequence[currentCount-1]][i])
        {            
            isVisited[i]=true;
            visitedSequence[currentCount]=i;
            DFS(currentCount+1);
            isVisited[i]=false;
        }
    }
}

int main()
{
    // input 입력
    cin >> cityNumber;
    for(int i=0; i<cityNumber; i++)
        for(int j=0; j<cityNumber; j++)
            cin >> W[i][j];
    
    // DFS 방식으로 n개의 도시의 방문 순서를 정하고 weight의 최소값을 구한다.
    for(int i=0; i<cityNumber; i++)
    {
        isVisited[i]=true;
        visitedSequence[0]=i;
        DFS(1);
        isVisited[i]=false;
    }
    
    // 결과 출력
    cout << minimumWeight;
    
    return 0;
}
