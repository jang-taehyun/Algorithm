#include <iostream>
using namespace std;

int main()
{
    int cnt;
    int x, y;
    int arr[5] = {0, };
    
    cin >> cnt;
    for(int i=1; i<=cnt; ++i)
    {
        cin >> x >> y;
        
        if(!x || !y)
            ++arr[4];
        else if(x > 0 && y > 0)
            ++arr[0];
        else if(x < 0 && y > 0)
            ++arr[1];
        else if(x < 0 && y < 0)
            ++arr[2];
        else
            ++arr[3];
    }
    
    for(int i=0; i<5; ++i)
    {
        if(i == 4)
            cout << "AXIS";
        else
            cout << "Q" << i+1;
        
        cout << ": " << arr[i] << '\n';
    }
    
    return 0;
}
