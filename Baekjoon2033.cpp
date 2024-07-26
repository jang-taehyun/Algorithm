#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string input;
    bool flag=false;
    int tmp;
    unsigned long long comp=10;
    
    cin >> input;
    
    reverse(input.begin(), input.end());
    
    for(int i=0; i<input.length()-1; i++)
    {
        reverse(input.begin(), input.end());
        if(stoull(input) < comp)
        {
            flag = true;
            break;
        }
        
        comp *= 10;
        reverse(input.begin(), input.end());
        tmp = input[i] - '0';
        input[i] = '0';
        
        if(tmp > 4)
        {
            flag = true;
            for(int j=i+1; j<input.length(); j++)
            {
                if(flag)
                {
                    flag = false;
                    
                    if(input[j]+1 > '9')
                    {
                        input[j] = '0';
                        flag=true;
                    }
                    else
                        input[j]++;
                }
                else
                    break;
            }
            
            if(flag)
            {
                input += "1";
                flag = false;
            }
        }
    }

    if(!flag)
        reverse(input.begin(), input.end());
    
    cout << input;
    
    return 0;
}
