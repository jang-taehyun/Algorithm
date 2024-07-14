#include <iostream>
using namespace std;

typedef unsigned int UINT;

int main()
{
    UINT num, len;
    UINT input[100];
    UINT res=0;
    
    cin >> num >> len;
    for(UINT i=0; i<num; i++)
        cin >> input[i];
    for(UINT i=1; i<=len; i++)
        for(int j=0; j<num; j++)
            if(!(i % input[j]))
            {
                res++;
                break;
            }
    
    cout << res;
    
    return 0;
}
