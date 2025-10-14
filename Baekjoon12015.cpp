#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len;
    vector<int> arr, v;
    int idx;
    
    cin >> len;
    
    arr.resize(len, 0);
    for(int i=0; i<len; ++i)
        cin >> arr[i];
    
    for(int i=0; i<len; ++i)
    {
        if(!v.empty() && v[v.size() - 1] >= arr[i])
        {
            idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[idx] = arr[i];
        }
        else
            v.push_back(arr[i]);
    }
    
    cout << v.size();
    
    return 0;
}
