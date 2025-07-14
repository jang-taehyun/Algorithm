#include <iostream>
using namespace std;

int main()
{
    int input;
    int sum1=0, sum2=0, MIN=101;
    
    for(int i=0; i<4; ++i)
    {
        cin >> input;
        sum1 += input;
        
        if(input < MIN)
            MIN = input;
    }
    
    sum1 -= MIN;
    MIN = 101;
    
    for(int i=0; i<2; ++i)
    {
        cin >> input;
        sum2 += input;
        
        if(input < MIN)
            MIN = input;
    }
    
    sum2 -= MIN;
    
    cout << (sum1 + sum2);
    
    return 0;
}
