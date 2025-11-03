#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> visit;
int cnt = 2;

void DFS(int cur)
{
    for(int i=0; i<graph[cur].size(); ++i)
        if(!visit[graph[cur][i]])
        {
            visit[graph[cur][i]] = cnt++;
            DFS(graph[cur][i]);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int node, edge, start;
    int n1, n2;
    
    cin >> node >> edge >> start;
    
    graph.resize(node+1);
    visit.resize(node+1, 0);
    while(edge--)
    {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    
    for(int i=1; i<=node; ++i)
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    
    visit[start] = 1;
    DFS(start);
    
    for(int i=1; i<=node; ++i)
        cout << visit[i] << '\n';
    
    return 0;
}
