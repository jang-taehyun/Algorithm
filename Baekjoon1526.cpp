#include <iostream>
using namespace std;

int main()
{
    int tmp;
    int bound;
    bool flag = false;
    
    cin >> bound;
    for(int i=bound; i>0; i--)
    {
        flag = true;
        tmp = i;
        
        while(tmp)
        {
            if(tmp % 10 != 4 && tmp % 10 != 7)
            {
                flag = false;
                break;
            }
            
            tmp /= 10;
        }
        
        if(flag)
        {
            cout << i;
            break;
        }
    }
    
    return 0;
}
