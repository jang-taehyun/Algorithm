#include <iostream>
using namespace std;

int main()
{
    int k, d, a;
    char tmp;
    
    cin >> k >> tmp >> d >> tmp >> a;
    
    if(k+a<d || !d)
        cout << "hasu";
    else
        cout << "gosu";
    
    return 0;
}
