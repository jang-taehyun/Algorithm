#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int len;
vector<vector<pair<int, int>>> graph;    // first : node, second : cost
vector<int> MinimumCost;

int Dijkstra(int start, int end)
{
    priority_queue<pair<int, int>> pq;    // first : cost, second : node
    int node, cost, nextNode, nextCost;
    
    MinimumCost.assign(len, INT_MAX);
    MinimumCost[start] = 0;
    
    pq.push(make_pair(0, -start));
    while(!pq.empty())
    {
        cost = -pq.top().first;
        node = -pq.top().second;
        pq.pop();
        
        if(cost > MinimumCost[node])
            continue;
        
        for(int i=0; i<graph[node].size(); ++i)
        {
            nextNode = graph[node][i].first;
            nextCost = graph[node][i].second + cost;
            
            if(nextCost < MinimumCost[nextNode])
            {
                MinimumCost[nextNode] = nextCost;
                pq.push(make_pair(-nextCost, -nextNode));
            }
        }
    }
    
    return MinimumCost[end];
}

int main()
{
    int CostCount, target;
    int s, e, c;
    int ret = 0, tmp;
    vector<int> StoX;
    
    cin >> len >> CostCount >> target;
    
    graph.resize(len);
    while(CostCount--)
    {
        cin >> s >> e >> c;
        graph[s-1].push_back(make_pair(e-1, c));
    }
    
    MinimumCost.resize(len, INT_MAX);
    StoX.resize(len, 0);
    for(int i=0; i<len; ++i)
    {
        if(i != target-1)
            StoX[i] = Dijkstra(i, target-1);
    }
    
    for(int i=0; i<len; ++i)
    {
        if(i != target-1)
        {
            tmp = Dijkstra(target-1, i);
            if(ret < StoX[i] + tmp)
                ret = StoX[i] + tmp;
        }
    }
    
    cout << ret;
    
    return 0;
}
