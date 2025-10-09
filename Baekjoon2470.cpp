#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int len;
    vector<int> arr;
    int s=0, e;
    int rs, re;
    unsigned int res = 2000000001;
    int tmp;
    
    cin >> len;
    
    arr.resize(len, 0);
    for(int i=0; i<len; ++i)
        cin >> arr[i];
    
    e = len-1;
    sort(arr.begin(), arr.end());
    while(s < e)
    {
        tmp = arr[s] + arr[e];
        
        if(abs(tmp) < res)
        {
            res = abs(tmp);
            rs = s;
            re = e;
        }
        
        if(tmp < 0)
            ++s;
        else
            --e;
    }
    
    cout << arr[rs] << ' ' << arr[re];
    
    return 0;
}
