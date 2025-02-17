#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input1, input2;
    int res = 51;
    int tmp = 0;
    int idx = 0;
    
    cin >> input1 >> input2;
    while(input1.length() + idx <= input2.length())
    {
        tmp = 0;
        for(int i=0; i<input1.length(); i++)
            if(input1[i] != input2[i+idx])
                tmp++;
        
        if(res > tmp)
            res = tmp;
        
        idx++;
    }
    
    cout << res;
    
    return 0;
}
