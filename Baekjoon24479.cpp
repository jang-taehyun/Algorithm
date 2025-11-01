#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int cnt = 2;

void DFS(int cur)
{
    for(int i=0; i<graph[cur].size(); ++i)
        if(!visited[graph[cur][i]])
        {
            visited[graph[cur][i]] = cnt;
            ++cnt;
            DFS(graph[cur][i]);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int node, edge, start;
    int s, e;
    
    cin >> node >> edge >> start;
    
    graph.resize(node+1);
    visited.resize(node+1, 0);
    for(int i=0; i<edge; ++i)
    {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    for(int i=1; i<=node; ++i)
        sort(graph[i].begin(), graph[i].end());
    
    visited[start] = 1;
    DFS(start);
    
    for(int i=1; i<=node; ++i)
        cout << visited[i] << '\n';
    
    return 0;
}
