#include <iostream>
using namespace std;

int main()
{
    int n;
    int sum=0;
    
    while(1)
    {
        cin >> n;
        
        if(n < 0)
            break;
        
        sum += n;
    }
    
    cout << sum;
    
    return 0;
}
