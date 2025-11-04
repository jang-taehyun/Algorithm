#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> graph;
    vector<int> visited;
    queue<int> s;
    int node, edge, start;
    int n1, n2;
    int cnt = 2;
    
    cin >> node >> edge >> start;
    graph.resize(node+1);
    visited.resize(node+1, 0);
    
    while(edge--)
    {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    
    for(int i=1; i<=node; ++i)
        sort(graph[i].begin(), graph[i].end());
    
    s.push(start);
    visited[start] = 1;
    while(!s.empty())
    {
        n1 = s.front();
        s.pop();
        
        for(int i=0; i<graph[n1].size(); ++i)
        {
            if(!visited[graph[n1][i]])
            {
                visited[graph[n1][i]] = cnt++;
                s.push(graph[n1][i]);
            }
        }
    }
    
    for(int i=1; i<=node; ++i)
        cout << visited[i] << '\n';
    
    return 0;
}
