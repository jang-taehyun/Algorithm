#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int len;
    vector<long long> arr;
    int left, right;
    long long res = 3000000001, sum;
    long long answer[3];
    
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
            if(i == left)
            {
                ++left;
                continue;
            }
            
            if(i == right)
            {
                --right;
                continue;
            }
            
            sum = arr[left] + arr[right] + arr[i];
            
            if(abs(sum) < abs(res))
            {
                res = sum;
                
                answer[0] = arr[left];
                answer[1] = arr[right];
                answer[2] = arr[i];
            }
            
            if(sum < 0)
                ++left;
            else
                --right;
        }
    }
    
    sort(answer, answer+3);
    for(int i=0; i<3; ++i)
        cout << answer[i] << ' ';
    
    return 0;
}
