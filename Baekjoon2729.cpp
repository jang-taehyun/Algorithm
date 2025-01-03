#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int test, op1, op2, adder, num;
    string input1, input2, res;
    
    cin >> test;
    cin.ignore();
    
    while(test--)
    {
        cin >> input1 >> input2;
        
        reverse(input1.begin(), input1.end());
        reverse(input2.begin(), input2.end());
        
        if(input1.length() > input2.length())
        {
            res = input1;
            input1 = input2;
            input2 = res;
        }
        
        adder = 0;
        res = "";
        
        for(int i=0; i<input1.length(); i++)
        {
            op1 = (input1[i] == '0' ? 0 : 1);
            op2 = (input2[i] == '0' ? 0 : 1);
            
            num = op1 + op2 + adder;
            adder = num / 2;
            
            res += to_string(num % 2);
        }
        
        if(input1.length() != input2.length())
        {
            for(int i=input1.length(); i<input2.length(); i++)
            {
                op2 = (input2[i] == '0' ? 0 : 1);
                
                num = op2 + adder;
                adder = (num / 2 ? 1 : 0);
                
                res += to_string(num % 2);
            }
        }
        
        if(adder)
        {
            res += "1";
        }
        
        reverse(res.begin(), res.end());
        while(res[0] == '0' && res.length() > 1)
            res.erase(res.begin());
        cout << res << '\n';
    }
    
    return 0;
}
