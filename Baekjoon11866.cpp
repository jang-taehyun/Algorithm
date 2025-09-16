#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> arr;
    int len, cnt;
    
    cin >> len >> cnt;
    for(int i=1; i<=len; ++i)
        arr.push(i);
    
    cout << '<';
    while(arr.size() > 1)
    {
        for(int i=0; i<cnt-1; ++i)
        {
            arr.push(arr.front());
            arr.pop();
        }
            
        cout << arr.front() << ", ";
        arr.pop();
    }
    
    cout << arr.front() << ">";
    
    return 0;
}
