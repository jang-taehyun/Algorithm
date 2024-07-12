#include <iostream>
#include <cmath>
using namespace std;

typedef struct _p
{
    int x;
    int y;
} Point;

int main()
{
    int s, e;
    Point sp, ep;
    int cur[4];
    int row=1;
    bool flag = false;
    
    cin >> s >> e;
    if(s > e)
    {
        int tmp = s;
        s = e;
        e = tmp;
    }
    
    for(int i=0; i<4; i++)
    {
        cur[i] = i+1;
        
        if(cur[i] == s)
        {
            sp.x = row;
            sp.y = i+1;
        }
        if(cur[i] == e)
        {
           flag = true;
            
           ep.x = row;
           ep.y = i+1;
        }
    }
        
    
    while(!flag)
    {
        row++;
        
        for(int i=0; i<4; i++)
        {
            cur[i] += 4;
            
            if(cur[i] == s)
            {
                sp.x = row;
                sp.y = i+1;
            }
            if(cur[i] == e)
            {
                flag = true;
                
                ep.x = row;
                ep.y = i+1;
            }
        }
    }
    
    cout << (abs(sp.x - ep.x) + abs(sp.y - ep.y));
    
    return 0;
}
