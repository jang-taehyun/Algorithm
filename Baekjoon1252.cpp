#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input1, input2, res;
    int adder=0, tmp=0;
    cin >> input1 >> input2;
    
    while(input1.length() != input2.length())
    {
        if(input1.length() > input2.length())
            input2 = "0" + input2;
        else
            input1 = "0" + input1;
    }
    
    for(int i=input1.length()-1; i>=0; i--)
    {
        tmp = (input1[i] - '0') + (input2[i] - '0') + adder;
        
        if(tmp > 1)
        {
            adder = 1;
            tmp %= 2;
        }
        else
            adder = 0;
        
        res = to_string(tmp) + res;
    }
    
    if(adder)
        res = "1" + res;
    
    while(res[0] == '0')
        res.erase(res.begin());
    
    if(res.length())
        cout << res;
    else
        cout << 0;
    
    return 0;
}
