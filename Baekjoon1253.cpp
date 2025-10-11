#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len;
    vector<long long> arr;
    bool flag = false;
    int left=0, right;
    int res=0;
    
    cin >> len;
    
    arr.resize(len, 0);
    for(int i=0; i<len; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<len; ++i)
    {
        left = 0;
        right = len-1;
        while(left < right)
        {
            if(arr[left] + arr[right] == arr[i])
            {
                if(i == left)
                    ++left;
                else if(i == right)
                    --right;
                else
                {
                    ++res;
                    break;
                }
            }
            else if(arr[left] + arr[right] > arr[i])
                --right;
            else
                ++left;
        }
    }
    
    cout << res;
    
    return 0;
}
