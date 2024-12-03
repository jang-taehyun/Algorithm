#include <iostream>
using namespace std;

int main()
{
    int res;
    int input;
    
    cin >> res;
    for(int i=0; i<9; i++)
    {
        cin >> input;
        res -= input;
    }
    
    cout << res;
    
    return 0;
}
