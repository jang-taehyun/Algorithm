#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<char> visited;
int k;
int res;

void Backtracking(int cur, int cnt)
{
    if(cnt >= arr.size())
    {
        ++res;
        return;
    }
    
    for(int i=0; i<arr.size(); ++i)
    {
        if(!visited[i] && cur + arr[i] - k >= 500)
        {
            visited[i] = 1;
            Backtracking(cur + arr[i] - k, cnt+1);
            visited[i] = 0;
        }
    }
}

int main()
{
    int len;
    
    cin >> len >> k;
    arr.resize(len, 0);
    visited.resize(len, 0);
    for(int i=0; i<len; ++i)
        cin >> arr[i];
    
    Backtracking(500, 0);
    cout << res;
    
    return 0;
}
