#include <iostream>
#include <string>
using namespace std;

int main()
{
    string op1, op2;
    string res;
    
    cin >> op1 >> op2;
    
    while(op1.length() != op2.length())
    {
        if(op1.length() > op2.length())
            op2 = "0" + op2;
        else
            op1 = "0" + op1;
    }
    
    for(int i=0; i<op1.length(); ++i)
        res += to_string((op1[i] - '0') + (op2[i] - '0'));
    
    cout << res;
    
    return 0;
}
