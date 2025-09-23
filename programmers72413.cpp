#include <string>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> MinimumCost;

void Dijkstra(int start, int n)
{
    priority_queue<pair<int, int>> pq;
    int node, nextNode;
    int cost, nextCost;
    
    MinimumCost.assign(n, INT_MAX);
    MinimumCost[start] = 0;
    pq.push(make_pair(0, -start));
    
    while(!pq.empty())
    {
        node = -pq.top().second;
        cost = -pq.top().first;
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
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<int> res;
    
    graph.resize(n);
    MinimumCost.resize(n);
    res.resize(n);
    for(int i=0; i<fares.size(); ++i)
    {
        graph[fares[i][0]-1].push_back(make_pair(fares[i][1]-1, fares[i][2]));
        graph[fares[i][1]-1].push_back(make_pair(fares[i][0]-1, fares[i][2]));
    }
    
    Dijkstra(s-1, n);
    for(int i=0; i<n; ++i)
    {
        if(i == s-1)
            res[i] = MinimumCost[a-1] + MinimumCost[b-1];
        else
            res[i] = MinimumCost[i];
    }
    
    for(int i=0; i<n; ++i)
    {
        if(i != s-1)
        {
            Dijkstra(i, n);
            res[i] += (MinimumCost[a-1] + MinimumCost[b-1]);
        }
    }
    
    answer = res[0];
    for(int i=0; i<n; ++i)
        if(answer > res[i])
            answer = res[i];
    
    return answer;
}
