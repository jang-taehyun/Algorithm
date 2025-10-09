#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int len;
    vector<int> arr;
    int s=0, e, rs=0, re;
    int sum, res=2000000001;
    
    cin >> len;
    
    arr.resize(len);
    for(int i=0; i<len; ++i)
        cin >> arr[i];
    
    e = len-1;
    re = len-1;
    while(s < e)
    {
        sum = arr[s] + arr[e];
        
        if(abs(sum) < res)
        {
            res = abs(sum);
            rs = s;
            re = e;
        }
        
        if(sum < 0)
            ++s;
        else
            --e;
    }
    
    cout << arr[rs] << ' ' << arr[re];
    
    return 0;
}
