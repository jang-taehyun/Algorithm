#include <iostream>
using namespace std;

int main()
{
    int test;
    int ai, bi, ar=0, br=0;
    
    cin >> test;
    while(test--)
    {
        cin >> ai >> bi;
        
        if(ai > bi)
            ar++;
        else if(ai < bi)
            br++;
    }
    
    cout << ar << ' ' << br;
    
    return 0;
}
