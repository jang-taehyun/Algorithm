#include <iostream>
#define MAX 101
#define MIN -1
using namespace std;

int main()
{
    int test;
    int len, input;
    int mx, mn;
    
    cin >> test;
    while(test--)
    {
        mx = MIN;
        mn = MAX;
        
        cin >> len;
        for(int i=0; i<len; i++)
        {
            cin >> input;
            
            if(mx < input)
                mx = input;
            if(mn > input)
                mn = input;
        }
        
        cout << (mx - mn) * 2 << '\n';
    }
    
    return 0;
}
