#include <iostream>
using namespace std;

int main()
{
    int n;
    int len=2;
    
    cin >> n;
    for(int i=1; i<=n; i++)
        len = len + (len - 1);
    cout << len * len;
    
    return 0;
}
