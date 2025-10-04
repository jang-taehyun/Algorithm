// https://school.programmers.co.kr/learn/courses/30/lessons/1844

#include <vector>
#include <queue>
using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int solution(vector<vector<int> > maps)
{
    int answer = 1;
    queue<pair<int, int>> q;
    int cnt = 0;
    int cy, cx, ny, nx;
    vector<vector<char>> visited;
    
    visited.resize(maps.size());
    for(int i=0; i<visited.size(); ++i)
        visited[i].resize(maps[i].size(), 0);
    
    visited[0][0] = 1;
    q.push(make_pair(0, 0));
    
    while(!q.empty())
    {
        cnt = q.size();
        while(cnt--)
        {
            cy = q.front().first;
            cx = q.front().second;
            q.pop();
            
            if(cy == maps.size()-1 && cx == maps[cy].size()-1)
                return answer;
            
            for(int i=0; i<4; ++i)
            {
                ny = cy + dy[i];
                nx = cx + dx[i];
                
                if(0 <= ny && ny < maps.size() && 0 <= nx && nx < maps[ny].size() && maps[ny][nx] && !visited[ny][nx])
                {
                    visited[ny][nx] = 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
        
        ++answer;
    }
    
    return -1;
}
