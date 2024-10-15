#include <iostream>
using namespace std;

int main()
{
    int test;
    int a[6];
    int b[7];
    int r1, r2;
    
    cin >> test;
    for(int j=1; j<=test; j++)
    {
        for(int i=0; i<6; i++)
            cin >> a[i];
        for(int i=0; i<7; i++)
            cin >> b[i];
        
        r1 = a[0] + (a[1] * 2) + (a[2] * 3) + (a[3] * 3) + (a[4] * 4) + (a[5] * 10);
        r2 = b[0] + (b[1] * 2) + (b[2] * 2) + (b[3] * 2) + (b[4] * 3) + (b[5] * 5) + (b[6] * 10);
        
        cout << "Battle " << j;
        if(r1 == r2)
            cout << ": No victor on this battle field\n";
        else if(r1 > r2)
            cout << ": Good triumphs over Evil\n";
        else
            cout << ": Evil eradicates all trace of Good\n";
    }
    
    return 0;
}
