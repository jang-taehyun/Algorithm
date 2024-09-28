#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int timeline[101];
    int start=101;
    int end=0;
    int cost[3];
    int tmp1, tmp2;
    int res=0;
    int adder;
    
    memset(timeline, 0, sizeof(timeline));
    
    for(int i=0; i<3; i++)
        cin >> cost[i];
    
    for(int i=0; i<3; i++)
    {
        cin >> tmp1 >> tmp2;
        
        if(tmp1 < start)
            start = tmp1;
        if(tmp2 > end)
            end = tmp2;
        
        for(int i=tmp1; i<tmp2; i++)
            timeline[i]++;
    }
    
    for(int i=start; i<end; i++)
    {
        if(timeline[i])
        {
            if(timeline[i] == 1)
            adder = cost[0];
            else if(timeline[i] == 2)
                adder = cost[1] * 2;
            else if(timeline[i] == 3)
                adder = cost[2] * 3;
        
            res += adder;
        }
    }
    
    cout << res;
    
    return 0;
}
