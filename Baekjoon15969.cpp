#include <iostream>
using namespace std;

int main()
{
    int cnt;
    int tmp;
    int maxNum=0, minNum=1001;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> tmp;
        
        if(tmp > maxNum)
            maxNum = tmp;
        if(tmp < minNum)
            minNum = tmp;
    }
    
    cout << (maxNum - minNum);
    
    return 0;
}
