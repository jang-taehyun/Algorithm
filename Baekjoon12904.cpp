#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string dest, target;
    string::iterator iter;
    bool res = false;
    
    cin >> dest >> target;
    
    while(!target.empty())
    {
        iter = target.end();
        --iter;
        
        if(*iter == 'B')
        {
            target.erase(iter);
            reverse(target.begin(), target.end());
        }
        else
            target.erase(iter);
        
        if(target == dest)
        {
            res = true;
            break;
        }
    }
    
    cout << res;
    
    return 0;
}
