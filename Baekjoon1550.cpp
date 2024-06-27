#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    unsigned int res=0, adder, mul=1;
    
    cin >> input;
    for(int i=input.length()-1; i>=0; i--)
    {
        if(input[i] >= '0' && input[i] <= '9')
            adder = input[i] - '0';
        else if(input[i] >= 'A' && input[i] <= 'F')
            adder = input[i] - 'A' + 10;
        
        res += (adder * mul);
        mul *= 16;
    }
    
    cout << res;
    
    return 0;
}
