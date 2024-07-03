#include <iostream>
using namespace std;

int main()
{
    int level;
    int grow, minus;
    int res=1;
    
    while(1)
    {
        cin >> level;
        if(!level)
            break;
        
        res = 1;
        for(int i=0; i<level; i++)
        {
            cin >> grow >> minus;
            res = res * grow - minus;
        }
        
        cout << res << '\n';
    }
    
    return 0;
}
