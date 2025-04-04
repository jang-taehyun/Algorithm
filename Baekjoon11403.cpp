#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int len;
bool res[100][100] = {false, };

bool BFS(int start, int target);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tmp;
    
    cin >> len;
    for(int i=0; i<len; ++i)
        for(int j=0; j<len; ++j)
        {
            cin >> tmp;
            res[i][j] = (tmp ? true : false);
        }
    
    for(int i=0; i<len; ++i)
        for(int j=0; j<len; ++j)
        {
            if(!res[i][j] && BFS(i, j))
                res[i][j] = true;
        }
    
    for(int i=0; i<len; ++i)
    {
        for(int j=0; j<len; ++j)
            cout << res[i][j] << ' ';
        cout << '\n';
    }
    
    return 0;
}

bool BFS(int start, int target)
{
    queue<int> q;
    int next, cur;
    bool visited[100][100] = {false, };
    
    q.push(start);
    
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        
        for(int i=0; i<len; ++i)
            if(!visited[cur][i] && res[cur][i])
            {
                if(i == target)
                    return true;
                
                visited[cur][i] = true;
                q.push(i);
            }
    }
    
    return false;
}
