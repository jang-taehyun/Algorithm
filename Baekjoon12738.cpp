#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len, idx;
    vector<int> arr, res;
    
    cin >> len;
    
    arr.resize(len, 0);
    for(int i=0; i<len; ++i)
        cin >> arr[i];
    
    for(int i=0; i<len; ++i)
    {
        if(!res.empty() && res[res.size() - 1] >= arr[i])
        {
            idx = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
            res[idx] = arr[i];
        }
        else
            res.push_back(arr[i]);
    }
    
    cout << res.size();
    
    return 0;
}
