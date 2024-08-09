#include <iostream>
using namespace std;

int main()
{
    int input;
    int res=0;
    
    for(int i=0; i<5; i++)
    {
        cin >> input;
        res = (res + (input * input)) % 10;
    }
    
    cout << res;
    
    return 0;
}
