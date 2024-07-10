#include <iostream>
#include <string>
using namespace std;

int main()
{
    string curt, endt;
    string tmp;
    string res;
    int minus=0;
    int op1, op2;
    
    cin >> curt >> endt;
    curt += ":";
    endt += ":";
    
    for(int i=curt.length()-1; i>=0; i-=3)
    {
        tmp = endt[i-2];
        tmp += endt[i-1];
        op1 = stoi(tmp);
        
        tmp = curt[i-2];
        tmp += curt[i-1];
        op2 = stoi(tmp);
        
        op1 -= minus;
        minus = 0;
        
        if(op1 < op2)
        {
            if(i == 2)
                op1 += 24;
            else
                op1 += 60;
            minus = 1;
        }
        
        tmp = to_string(op1 - op2);
        if(tmp.length() < 2)
            tmp = "0" + tmp;
        
        res = tmp + res;
        if(i != 2)
            res = ":" + res;
    }
    
    cout << res;
    
    
    return 0;
}
