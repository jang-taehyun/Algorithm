#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    bool IsFull[100];
    int people;
    int tmp;
    int res=0;
    
    memset(IsFull, false, sizeof(IsFull));
    
    cin >> people;
    while(people--)
    {
        cin >> tmp;
        
        if(IsFull[tmp])
            res++;
        else
            IsFull[tmp] = true;
    }
    
    cout << res;
    
    return 0;
}
