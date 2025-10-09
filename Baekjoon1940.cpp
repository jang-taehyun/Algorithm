#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int len, bound;
    vector<int> arr;
    int s, e;
    int res = 0;
    
    cin >> len >> bound;
    
    arr.resize(len, 0);
    for(int i=0; i<len; ++i)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    
    s = 0;
    e = len-1;
    while(s < e)
    {
        if(arr[s] + arr[e] == bound)
        {
            ++res;
            ++s;
        }
        else if(arr[s] + arr[e] < bound)
            ++s;
        else
            --e;
    }
    
    cout << res;
    
    return 0;
}
