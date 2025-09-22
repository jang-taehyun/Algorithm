#include <string>
#include <vector>

using namespace std;

int dy[3] = {1, 0, -1};
int dx[3] = {0, 1, -1};

void DFS(vector<vector<int>>& tri, vector<vector<int>>& visited, int cnt, int py, int px, int dir, int n)
{
    int ny = py + dy[dir];
    int nx = px + dx[dir];
    
    if(ny < 0 || ny >= n || nx < 0 || nx >= tri[ny].size() || visited[ny][nx])
    {
        dir = (dir + 1) % 3;
        ny = py + dy[dir];
        nx = px + dx[dir];
        
        if(ny < 0 || ny >= n || nx < 0 || nx >= tri[ny].size() || visited[ny][nx])
            return;
    }
    
    visited[ny][nx] = 1;
    tri[ny][nx] = cnt;
    
    DFS(tri, visited, cnt+1, ny, nx, dir, n);
}

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> triangle;
    vector<vector<int>> visited;
    int idx=0;
    
    answer.resize((n * (n+1) / 2), 0);
    
    triangle.resize(n);
    visited.resize(n);
    for(int i=0; i<n; ++i)
    {
        triangle[i].resize(i+1, 0);
        visited[i].resize(i+1, 0);
    }
    
    triangle[0][0] = 1;
    visited[0][0] = 1;
    DFS(triangle, visited, 2, 0, 0, 0, n);
    
    for(int i=0; i<triangle.size(); ++i)
        for(int j=0; j<triangle[i].size(); ++j)
        {
            answer[idx] = triangle[i][j];
            ++idx;
        }
    
    return answer;
}
