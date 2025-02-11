#include <iostream>
#include <stack>
using namespace std;

typedef struct _s_
{
    int Height;
    int ValidCount;
} Person;

int main()
{
    stack<Person> s;
    int n;
    long long res = 0;
    int Valid;
    int len;
    
    cin >> len;
    while(len--)
    {
        cin >> n;
        
        Valid = 1;
        while(!s.empty() && s.top().Height <= n)
        {
            res += (long long)s.top().ValidCount;
            
            if(s.top().Height == n)
                Valid += s.top().ValidCount;
            s.pop();
        }
        
        if(!s.empty())
            res++;
        s.push({n, Valid});
    }
    
    cout << res;
    
    return 0;
}
