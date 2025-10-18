#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int len, idx;
    vector<pair<int, int>> arr;
    vector<int> res;
    
    cin >> len;
    
    arr.resize(len);
    for(int i=0; i<len; ++i)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<len; ++i)
    {
        if(!res.empty() && res[res.size() - 1] >= arr[i].second)
        {
            idx = lower_bound(res.begin(), res.end(), arr[i].second) - res.begin();
            res[idx] = arr[i].second;
        }
        else
            res.push_back(arr[i].second);
    }
    
    cout << (len - res.size());
    
    return 0;
}
