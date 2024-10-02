#include <iostream>
using namespace std;

int arr[9];
int res[7];
bool visited[9];

bool DFS(int cur, int start, int sum)
{
    if(cur >= 7)
    {
        if(sum > 100 || sum < 100)
            return false;
    
        if(sum == 100)
        {
            for(int i=0; i<7; i++)
                cout << res[i] << '\n';
            return true;
        }
    }
    
    for(int i=start; i<9; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            res[cur] = arr[i];
            
            if(DFS(cur+1, i, sum+res[cur]))
                return true;
            
            visited[i] = false;
        }
    }
    
    return false;
}

int main()
{
    for(int i=0; i<9; i++)
        cin >> arr[i];
    
    DFS(0, 0, 0);
    
    return 0;
}
