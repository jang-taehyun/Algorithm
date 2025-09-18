#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int NodeCount;
vector<pair<int, int>> weight[1000];
int MinimumCost[1000];

void Dijkstra(int start)
{
    // first : idx, second : cost
    priority_queue<pair<int, int>> q;
    int idx = 0, cost = 0;
    
    // 최소 cost 배열 초기화
    for(int i=0; i<NodeCount; ++i)
        MinimumCost[i] = INF;
    MinimumCost[start] = 0;
    
    // 시작 node를 우선순위 큐에 넣기
    q.push(make_pair(-start, 0));
    
    while(!q.empty())
    {
        // 우선순위 큐에서 하나 꺼내기.
        idx = -q.top().first;
        cost = -q.top().second;
        q.pop();
        
        // 우선순위 큐에서 꺼낸 것의 cost가 최소 비용이 아닌 경우 스킵
        if(cost > MinimumCost[idx])
            continue;

        // 현재 선택된 node와 연결된 node들 중 탐색하지 않는 node들을 탐색해 최소 cost로 업데이트
        for(int i=0; i<weight[idx].size(); ++i)
        {
            // 현재 선택된 node(idx)가 가지고 있는 최소 cost + 현재 선택된 node(idx)와 인접한 다른 node(weight[idx][i].first) 사이의 cost
            // vs 시작 node에서 인접한 node(weight[idx][i].first) 사이의 cost
            if(cost + weight[idx][i].second < MinimumCost[weight[idx][i].first])
            {
                // cost 값 갱신
                MinimumCost[weight[idx][i].first] = weight[idx][i].second + cost;
                
                // 우선순위 큐에 넣기
                q.push(make_pair(-weight[idx][i].first, -MinimumCost[weight[idx][i].first]));
            }
        }
    }
}

int main()
{
    int s, e, c, CostCount;
    
    cin >> NodeCount >> CostCount;
    
    while(CostCount--)
    {
        cin >> s >> e >> c;
        weight[s-1].push_back(make_pair(e-1, c));
    }
    
    cin >> s >> e;
    Dijkstra(s-1);
    cout << MinimumCost[e-1];
    
    return 0;
}
