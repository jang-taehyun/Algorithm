#include <iostream>
using namespace std;

int main()
{
    int test;
    int n, m;
    int res = 1;
    
    cin >> test;
    while(test--)
    {
        cin >> n >> m;
        
        for(int i=0; i<n; i++)
        {
            res *= (m-i);
            res /= (i+1);
        }
        
        cout << res << '\n';
        res = 1;
    }
    
    return 0;
}
