#include <iostream>
#include <string>
using namespace std;
typedef unsigned long UL;

bool IsInRange(int n)
{
    if(n % 100 >= 60 || (n / 100) % 100 >= 60 || n / 10000 >= 24)
        return false;
    return true;
}

int main()
{
    string start, end;
    UL istart, iend;
    UL res=0;

    for(UL i=0; i<3; i++)
    {
        cin >> start >> end;
        
        start.erase(start.begin()+5);
        start.erase(start.begin()+2);
        end.erase(end.begin()+5);
        end.erase(end.begin()+2);
        
        istart=stoul(start);
        iend=stoul(end);
        
        if(istart < iend)
        {
            for(UL j=istart; j<=iend; j++)
                if(IsInRange(j) && !(j%3))
                    res++;
        }
        else
        {
            for(UL j=istart; j<240000; j++)
                if(IsInRange(j) && !(j%3))
                    res++;

            for(UL j=0; j<=iend; j++)
                if(IsInRange(j) && !(j%3))
                    res++;
        }
        
        cout << res << '\n';
        res=0;
    }
    
    return 0;
}
