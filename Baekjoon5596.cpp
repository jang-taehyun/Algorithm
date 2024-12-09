#include <iostream>
using namespace std;

int main()
{
    int input;
    int res[2] = { 0, 0 };
    
    for(int i=0; i<2; i++)
        for(int j=0; j<4; j++)
        {
            cin >> input;
            res[i] += input;
        }
    
    cout << (res[0] >= res[1] ? res[0] : res[1]);
    
    return 0;
}
