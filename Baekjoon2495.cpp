#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int res=1;
    int tmp=1;
    
    for(int j=0; j<3; j++)
    {
        cin >> input;
        
        tmp = 1;
        res = 1;
        
        for(int i=1; i<input.length(); i++)
        {
            if(input[i] == input[i-1])
                tmp++;
            else
            {
                if(tmp > res)
                    res = tmp;
                tmp = 1;
            }
        }
        
        if(tmp > res)
            res = tmp;
        
        cout << res << '\n';
    }
    
    return 0;
}
