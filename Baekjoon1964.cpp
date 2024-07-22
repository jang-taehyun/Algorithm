#include <iostream>
using namespace std;

typedef unsigned int UINT;

int main()
{
    UINT len;
    UINT sum=0;
    
    cin >> len;
    
    len++;
    sum += ((len * 5 - 5) % 45678);
    while(--len > 1)
        sum = (sum + ((len * 5 - 5) - (len * 2 - 1))) % 45678;
    
    cout << sum;
    
    return 0;
}
