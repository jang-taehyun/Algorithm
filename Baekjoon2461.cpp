#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr[1000];
    int team, len;
    int idx[1000] = {0, };
    int max_num, min_num, max_idx, min_idx, tmp;
    bool IsFinish = false;
    int res = 0x7f7f7f7f;
    
    cin >> team >> len;
    for(int i=0; i<team; ++i)
        for(int j=0; j<len; ++j)
        {
            cin >> tmp;
            arr[i].push_back(tmp);
        }
    
    for(int i=0; i<team; ++i)
        sort(arr[i].begin(), arr[i].end());
    
    while(!IsFinish)
    {
        max_num = -1;
        min_num = 0x7f7f7f7f;
        
        for(int i=0; i<team; ++i)
        {
            if(arr[i][idx[i]] > max_num)
            {
                max_num = arr[i][idx[i]];
                max_idx = i;
            }
            if(arr[i][idx[i]] < min_num)
            {
                min_num = arr[i][idx[i]];
                min_idx = i;
            }
        }
        
        tmp = max_num - min_num;
        if(res > tmp)
            res = tmp;
        
        idx[min_idx]++;
        if(idx[min_idx] >= len)
            break;
    }
    
    cout << res;
    
    return 0;
}
