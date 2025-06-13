#include <iostream>
using namespace std;

int main()
{
    int len, cnt;
    int arr[101] = {0, };
    int s, e;
    int tmp;
    
    cin >> len >> cnt;
    for(int i=1; i<=len; ++i)
        arr[i] = i;
    
    while(cnt--)
    {
        cin >> s >> e;
        
        for(int i=0; i<=(e-s)/2; ++i)
        {
            tmp = arr[s+i];
            arr[s+i] = arr[e-i];
            arr[e-i] = tmp;
        }
    }
    
    for(int i=1; i<=len; ++i)
        cout << arr[i] << ' ';
    
    return 0;
}
