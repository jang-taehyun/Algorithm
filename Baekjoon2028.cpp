#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef unsigned int UINT;

int main()
{
    UINT test;
    string tmp1, tmp2;
    UINT input;
    bool flag=true;
    
    cin >> test;
    while(test--)
    {
        cin >> input;
        
        tmp1 = to_string(input);
        input *= input;
        tmp2 = to_string(input);
        
        reverse(tmp1.begin(), tmp1.end());
        reverse(tmp2.begin(), tmp2.end());
        
        for(int i=0; i<tmp1.length(); i++)
        {
            if(tmp1[i] != tmp2[i])
            {
                flag=false;
                break;
            }
        }
        
        cout << (flag ? "YES" : "NO") << '\n';
        
        flag=true;
    }
    
    return 0;
}
