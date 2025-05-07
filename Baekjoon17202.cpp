#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input1, input2;
    string tmp1, tmp2;
    bool flag = false;
    int sum=0;
    
    cin >> input1 >> input2;
    
    for(int i=0; i<input1.length(); ++i)
    {
        tmp1 += input1[i];
        tmp1 += input2[i];
    }
    
    while(1)
    {
        if(!flag)
        {
            if(tmp1.length() <= 2)
                break;
            
            flag = true;
            
            for(int i=0; i<tmp1.length()-1; ++i)
            {
                sum = ((tmp1[i] - '0') + (tmp1[i+1] - '0')) % 10;
                tmp2 += to_string(sum);
            }
            
            tmp1 = "";
        }
        else
        {
            if(tmp2.length() <= 2)
                break;
            
            flag = false;
            
            for(int i=0; i<tmp2.length()-1; ++i)
            {
                sum = ((tmp2[i] - '0') + (tmp2[i+1] - '0')) % 10;
                tmp1 += to_string(sum);
            }
            
            tmp2 = "";
        }
    }
    
    cout << (!flag ? tmp1 : tmp2);
    
    return 0;
}
