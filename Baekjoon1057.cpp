#include <iostream>
using namespace std;

int main()
{
    int round;
    int target[2] = {0, };
    int res = 0;
    
    cin >> round >> target[0] >> target[1];
    
    while(target[0] != target[1])
    {
        for(int i=0; i<2; i++)
            target[i] = (target[i] + 1) / 2;
        res++;
    }
    
    cout << res;
    
    return 0;
}
