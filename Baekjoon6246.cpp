#include <iostream>
using namespace std;

int main()
{
    int len, count;
    int start, interval;
    bool IsExist[10000] = {false, };
    int res=0;
    
    cin >> len >> count;
    while(count--)
    {
        cin >> start >> interval;
        
        for(int i=start-1; i<len; i+=interval)
            if(!IsExist[i])
                IsExist[i] = true;
    }
    
    for(int i=0; i<len; i++)
        if(!IsExist[i])
            res++;
    
    cout << res;
    
    return 0;
}
