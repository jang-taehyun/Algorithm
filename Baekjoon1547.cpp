#include <iostream>
using namespace std;

int main()
{
    bool IsBall[3];
    int move;
    int from, to;
    bool tmp;
    
    IsBall[0] = true;
    IsBall[1] = false;
    IsBall[2] = false;
    
    cin >> move;
    while(move--)
    {
        cin >> from >> to;
        
        from--;
        to--;
        
        tmp = IsBall[from];
        IsBall[from] = IsBall[to];
        IsBall[to] = tmp;
    }
    
    for(int i=0; i<3; i++)
        if(IsBall[i])
            cout << i+1;
    
    return 0;
}
