#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int test;
    int p1=0, p2=0;
    double x, y, tmp;
    
    cin >> test;
    while(test--)
    {
        for(int i=0; i<3; i++)
        {
            cin >> x >> y;
            tmp = sqrt(x * x + y * y);
            
            if(tmp <= 3.f)
                p1 += 100;
            else if(tmp <= 6.f)
                p1 += 80;
            else if(tmp <= 9.f)
                p1 += 60;
            else if(tmp <= 12.f)
                p1 += 40;
            else if(tmp <= 15.f)
                p1 += 20;
        }
        
        for(int i=0; i<3; i++)
        {
            cin >> x >> y;
            tmp = sqrt(x * x + y * y);
            
            if(tmp <= 3.f)
                p2 += 100;
            else if(tmp <= 6.f)
                p2 += 80;
            else if(tmp <= 9.f)
                p2 += 60;
            else if(tmp <= 12.f)
                p2 += 40;
            else if(tmp <= 15.f)
                p2 += 20;
        }
        
        cout << "SCORE: " << p1 << " to " << p2 << ", ";
        if(p1 == p2)
            cout << "TIE." << '\n';
        else
            cout << "PLAYER " << (p1 > p2 ? "1" : "2") << " WINS." << '\n';
        
        p1 = 0;
        p2 = 0;
    }
    
    return 0;
}
