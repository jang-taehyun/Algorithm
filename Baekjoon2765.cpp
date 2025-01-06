#include <iostream>
using namespace std;

int main()
{
    int idx = 1;
    double diameter, cycle, sec;
    double dist, speed;
    
    cout.precision(2);
    cout << fixed;
    
    while(1)
    {
        cin >> diameter >> cycle >> sec;
        
        if(!cycle)
            break;
        
        dist = diameter / (5280.f * 12.f) * cycle * 3.1415927f;
        speed = dist / sec * 3600.f;
        
        cout << "Trip #" << idx << ": " << dist << ' ' << speed << '\n';
        idx++;
    }
    
    return 0;
}
