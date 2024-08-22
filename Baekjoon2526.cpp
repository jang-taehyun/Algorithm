#include <iostream>
using namespace std;

bool visited[1000];
int res=0;

int main()
{
    int n, p;
    int tmp;
    int s = -1;
    
    cin >> n >> p;
    
    tmp = n;
    while(1)
    {
        if(visited[tmp])
        {
            if(tmp == s)
                break;
            
            if(s == -1)
                s = tmp;
            
            res++;
        }
        else
            visited[tmp] = true;
        
        tmp = (tmp * n) % p;
    }
    
    cout << res;
    
    return 0;
}
