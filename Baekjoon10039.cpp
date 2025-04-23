#include <iostream>
using namespace std;

int main()
{
    int tmp;
    int res = 0;
    
    for(int i=0; i<5; ++i)
    {
        cin >> tmp;
        res += (tmp >= 40 ? tmp : 40);
    }
    
    cout << res/5;
    
    return 0;
}
