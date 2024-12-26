#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int test;
    int round;
    bool IsClose[101] = {false, };
    int res=0;
    
    cin >> test;
    while(test--)
    {
        cin >> round;
        
        for(int i=2; i<=round; i++)
        {
            for(int j=i; j<=round; j+=i)
                IsClose[j] = !IsClose[j];
        }
        
        for(int i=1; i<=round; i++)
            if(!IsClose[i])
                res++;
        
        cout << res << '\n';
        
        res = 0;
        memset(IsClose, false, sizeof(IsClose));
    }
    
    return 0;
}
