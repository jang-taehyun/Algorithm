#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, h, w;
    int r1, r2;
    double a;
    cin >> n >> h >> w;
    
    a = (double)pow(n, 2) / (double)(pow(h, 2) + pow(w, 2));
    a = sqrt(a);
    r1 = (int)(a * h);
    r2 = (int)(a * w);
    
    cout << r1 << ' ' << r2;
    
    return 0;
}
