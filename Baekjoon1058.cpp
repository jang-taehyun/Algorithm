#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> f[50];
bool visited[50] = {false, };
int len;
char tmp;
int res = 0, cur = 0;

void DFS(int idx, int cnt)
{
    if(cnt >= 2)
        return;
    
    queue<int> q;
    for(int i=0; i<f[idx].size(); i++)
        if(!visited[f[idx][i]])
        {
            visited[f[idx][i]] = true;
            cur++;
            q.push(f[idx][i]);
        }
    
    while(!q.empty())
    {
        DFS(q.front(), cnt+1);
        q.pop();
    }
}

int main()
{
    cin >> len;
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            cin >> tmp;
            
            if(tmp == 'Y')
                f[i].push_back(j);
        }
    }
    
    for(int i=0; i<len; i++)
    {
        visited[i] = true;
        DFS(i, 0);
        if(cur > res)
            res = cur;
        
        memset(visited, false, sizeof(visited));
        cur = 0;
    }
    
    cout << res;
    
    return 0;
}
