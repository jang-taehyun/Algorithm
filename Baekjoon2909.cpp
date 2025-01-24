#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int digits, adder = 0, tmp;
    
    cin >> input >> digits;
    
    for(int i=1; i<=input.length(); i++)
    {
        if(i < digits)
            input[input.length() - i] = '0';
        else if(i == digits)
        {
            tmp = input[input.length() - i] - '0';
            
            if(tmp >= 5)
                adder = 1;
            else
                adder = 0;
            
            input[input.length() - i] = '0';
        }
        else
        {
            tmp = input[input.length() - i] - '0';
            
            tmp += adder;
            adder = 0;
            
            if(tmp > 9)
            {
                tmp %= 10;
                adder = 1;
            }
            
            input[input.length() - i] = (char)(tmp + '0');
        }
    }
    
    if(adder)
    {
        adder = 0;
        input = "1" + input;
    }
    
    while(input.length() > 1 && input[0] == '0')
        input.erase(input.begin());
    
    cout << input;
    
    return 0;
}
