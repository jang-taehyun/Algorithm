#include <iostream>
using namespace std;

int main()
{
    int len;
    int input[50];
    int n=0, res=0;
    
    cin >> len;
    for(int i=0; i<len; i++)
    {
        cin >> input[i];
        
        if(input[i] > n)
        {
            res++;
            n = input[i];
        }
    }
    cout << res << '\n';
    
    res=0;
    n=0;
    for(int i=len-1; i>=0; i--)
    {
        if(input[i] > n)
        {
            res++;
            n = input[i];
        }
    }
    cout << res;
    
    return 0;
}
