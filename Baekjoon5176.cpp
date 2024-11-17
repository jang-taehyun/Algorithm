#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int test;
    bool IsFull[500];
    int count, bound;
    int tmp;
    int res;
    
    cin >> test;
    while(test--)
    {
        memset(IsFull, 0, sizeof(IsFull));
        res = 0;
        
        cin >> count >> bound;
        
        for(int i=0; i<count; i++)
        {
            cin >> tmp;
            
            if(IsFull[tmp-1])
                res++;
            else
                IsFull[tmp-1] = true;
        }
        
        cout << res << '\n';
    }
    
    return 0;
}
