#include <iostream>
using namespace std;

int main()
{
    int input;
    int res = 0;
    
    for(int i=0; i<4; i++)
    {
        cin >> input;
        res += input;
    }
    
    cout << (res / 60) << '\n' << (res % 60);
    
    return 0;
}
