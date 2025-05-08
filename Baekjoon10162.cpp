#include <iostream>
using namespace std;

int main()
{
    int input;
    int res[3] = {0, };
    int divider[3] = {300, 60, 10};
    
    cin >> input;
    
    for(int i=0; i<3; ++i)
    {
        res[i] += (input / divider[i]);
        input %= divider[i];
    }
    
    if(!input)
        for(int i=0; i<3; ++i)
            cout << res[i] << ' ';
    else
        cout << -1;
        
    return 0;
}
