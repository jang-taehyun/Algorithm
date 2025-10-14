#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len;
    vector<int> arr[4];
    vector<int> comp;
    int sum;
    long long res=0, s, e;
    
    cin >> len;
    for(int i=0; i<4; ++i)
        arr[i].resize(len, 0);
    
    for(int i=0; i<len; ++i)
        for(int j=0; j<4; ++j)
            cin >> arr[j][i];
    
    for(int i=0; i<len; ++i)
        for(int j=0; j<len; ++j)
            comp.push_back(arr[2][i] + arr[3][j]);
    sort(comp.begin(), comp.end());
    
    for(int i=0; i<len; ++i)
    {
        for(int j=0; j<len; ++j)
        {
            sum = arr[0][i] + arr[1][j];
            
            if(comp[0] <= -sum && -sum <= comp[comp.size() - 1])
            {
                s = lower_bound(comp.begin(), comp.end(), -sum) - comp.begin();
                e = upper_bound(comp.begin(), comp.end(), -sum) - comp.begin();
                res += (e - s);
            }
        }
    }
    
    cout << res;
    
    return 0;
}
