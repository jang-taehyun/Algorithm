#include <iostream>
using namespace std;

int main()
{
    double w, h, x, y;
    int p;
    double X, Y;
    double r;
    double tmp;
    int res = 0;
    
    cin >> w >> h >> x >> y >> p;
    r = h / 2.f;
    r *= r;
    
    while(p--)
    {
        cin >> X >> Y;
        
        if((X >= x && X <= (x + w)) && (Y >= y && Y <= (y + h)))
        {
            res++;
            continue;
        }
        
        tmp = ((X - x) * (X - x)) + ((Y - (y + (h/2.f))) * (Y - (y + (h/2.f))));
        if(tmp <= r)
        {
            res++;
            continue;
        }
        
        tmp = ((X - (x + w)) * (X - (x + w))) + ((Y - (y + (h/2.f))) * (Y - (y + (h/2.f))));
        if(tmp <= r)
            res++;
    }
    
    cout << res;
    
    return 0;
}
