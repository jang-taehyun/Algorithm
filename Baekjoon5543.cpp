#include <iostream>
using namespace std;

int main()
{
    int hamburger[3];
    int drink[2];
    int res = 5000;
    
    for(int i=0; i<3; i++)
        cin >> hamburger[i];
    for(int i=0; i<2; i++)
        cin >> drink[i];
    
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        {
            if(res > (hamburger[i] + drink[j] - 50))
                res = hamburger[i] + drink[j] - 50;
        }
    }
    
    cout << res;
    
    return 0;
}
