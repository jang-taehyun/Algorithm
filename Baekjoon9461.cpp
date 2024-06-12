#include <iostream>
using namespace std;

int main()
{
    int test, input;
    unsigned long long res[101];
    
    res[1] = 1;
    res[2] = 1;
    res[3] = 1;
    
    res[4] = 2;
    res[5] = 2;
    
    res[6] = 3;
    res[7] = 4;
    res[8] = 5;
    
    for(int i=9; i<101; i++)
        res[i] = res[i-1] + res[i-5];
    
    cin >> test;
    while(test--)
    {
        cin >> input;
        cout << res[input] << '\n';
    }
    
    return 0;
}
