#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input1, input2;
    string res;
    int tmp1=0, tmp2=0, tmp3=0, tmp4=0;
    
    cin >> input1;
    input2 = input1 + "0000";
    
    for(int i=input2.length()-1; i>=4; i--)
    {
        tmp1 = input1[i-4] - '0';
        tmp2 = input2[i] - '0';
        
        tmp4 = tmp1 + tmp2 + tmp3;
        
        switch(tmp4)
        {
            case 3:
                {
                    tmp3 = 1;
                    res = "1" + res;
                }
                break;
            case 2:
                {
                    tmp3 = 1;
                    res = "0" + res;
                }
                break;
            default:
                {
                    tmp3 = 0;
                    res = to_string(tmp4) + res;
                }
                break;
        }
    }
    
    for(int i=3; i>=0; i--)
    {
        tmp2 = input2[i] - '0';
        tmp4 = tmp2 + tmp3;
        
        if(2 == tmp4)
        {
            tmp3 = 1;
            res = "0" + res;
        }
        else
        {
            tmp3 = 0;
            res = to_string(tmp4) + res;
        }
    }
    
    if(tmp3)
        res = "1" + res;
    
    cout << res;
    
    return 0;
}
