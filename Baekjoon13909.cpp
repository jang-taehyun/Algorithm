#include <iostream>
using namespace std;

int main()
{
    int len, cnt=0;
    
    cin >> len;
    for(int i=1; i*i<=len; ++i)
        ++cnt;
    
    cout << cnt;
    
    return 0;
}
