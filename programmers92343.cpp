#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    vector<char> nodes;
    int visited=0;
    int sheep=0;
    int wolf=0;
    
    Node& operator=(Node& other)
    {
        nodes = other.nodes;
        visited = other.visited;
        sheep = other.sheep;
        wolf = other.wolf;
        
        return *this;
    }
};

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 1;
    Node cur, next;
    vector<vector<int>> graph(info.size());
    queue<Node> q;
    int idx;
    
    for(int i=0; i<edges.size(); ++i)
        graph[edges[i][0]].push_back(edges[i][1]);
    
    cur.nodes.push_back(0);
    cur.visited = 1;
    cur.sheep = 1;
    q.push(cur);
    
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        
        for(int i=0; i<cur.nodes.size(); ++i)
        {
            idx = cur.nodes[i];
            for(int j=0; j<graph[idx].size(); ++j)
            {
                if(!(cur.visited & 1 << graph[idx][j]))
                {
                    if(info[graph[idx][j]])
                    {
                        next.sheep = cur.sheep;
                        next.wolf = cur.wolf + 1;
                        
                        if(next.wolf >= next.sheep)
                            continue;
                    }
                    else
                    {
                        next.sheep = cur.sheep + 1;
                        next.wolf = cur.wolf;
                        answer = (next.sheep > answer ? next.sheep : answer);
                    }
                    
                    next.nodes = cur.nodes;
                    next.nodes.push_back(graph[idx][j]);
                    
                    next.visited = cur.visited | 1 << graph[idx][j];
                    
                    q.push(next);
                }
            }
        }
    }
    
    return answer;
}
