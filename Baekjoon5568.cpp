#include <iostream>
#include <set>
#include <string>
using namespace std;

int len, cnt;
int arr[10] = {0, };
int num[10] = {0, };
bool visited[10] = {false, };
set<string> s;

void DFS(int cur)
{
    if(cur >= cnt)
    {
        string str;
        set<string>::iterator iter;
        
        for(int i=0; i<cnt; ++i)
            str += to_string(num[i]);
        
        iter = s.find(str);
        
        if(iter == s.end())
            s.insert(str);
        return;
    }
    
    for(int i=0; i<len; ++i)
    {
        if(!visited[i])
        {
            visited[i] = true;
            num[cur] = arr[i];
            DFS(cur+1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> len >> cnt;
    for(int i=0; i<len; ++i)
        cin >> arr[i];
    
    DFS(0);
    
    cout << s.size();
    
    return 0;
}
