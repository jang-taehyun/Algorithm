#include <iostream>
using namespace std;

int main()
{
    int cnt;
    int n;
    int res = 1;
    
    cin >> cnt;
    for(int i=0; i<cnt; i++)
    {
        cin >> n;
        n--;
        res += n;
    }
    
    cout << res;
    
    return 0;
}
