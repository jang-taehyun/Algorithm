#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input, tmp1, tmp2;
    int test, idx=0;
    int op1, op2;
    
    cin >> test;
    while(test--)
    {
        idx=0;
        tmp1.clear();
        tmp2.clear();
        
        cin >> input;
        
        if("P=NP" == input)
        {
            cout << "skipped" << '\n';
            continue;
        }
        
        while(idx < input.length() && input[idx] != '+')
        {
            tmp1 += input[idx];
            idx++;
        }
        op1 = stoi(tmp1);
        
        idx++;
        while(idx < input.length() && input[idx] != '+')
        {
            tmp2 += input[idx];
            idx++;
        }
        op2 = stoi(tmp2);
        
        cout << op1+op2 << '\n';
    }
    
    return 0;
}
