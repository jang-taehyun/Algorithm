#include <iostream>
using namespace std;

int arr[250001] = { 0, };

int main()
{
    int cnt, len, tmp;
    int res1=0, res2=0;
    
    cin >> cnt >> len;
    for(int i=1; i<=cnt; ++i)
    {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    
    for(int i=len; i<=cnt; ++i)
    {
        tmp = arr[i] - arr[i-len];
        
        if(tmp > res1)
        {
            res1 = tmp;
            res2 = 1;
        }
        else if(tmp == res1)
            ++res2;
    }
    
    if(res1)
        cout << res1 << '\n' << res2;
    else
        cout << "SAD";
    
    return 0;
}
