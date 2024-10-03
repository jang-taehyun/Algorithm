#include <iostream>
using namespace std;

int main()
{
    int test;
    int r, c;
    int tmp;
    
    cin >> test >> r >> c;
    
    while(test--)
    {
        cin >> tmp;
        
        if(tmp > r && tmp > c && tmp * tmp > (r * r + c * c))
            cout << "NE" << '\n';
        else
            cout << "DA" << '\n';
    }
    
    return 0;
}
