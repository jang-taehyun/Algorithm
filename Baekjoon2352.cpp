#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len=0;
    int arr[40000] = {0, };
    int left, right, mid, input;
    int res = 0;
    
    cin >> len;
    for(int i=0; i<len; ++i)
    {
        cin >> input;
        
        if(res && arr[res - 1] >= input)
        {
            left = 0;
            right = res - 1;
            while(left < right)
            {
                mid = (left + right) / 2;
                
                if(arr[mid] > input)
                    right = mid;
                else
                    left = mid+1;
            }
            
            arr[right] = input;
        }
        else
        {
            arr[res] = input;
            ++res;
        }
            
    }
    
    cout << res;
    
    return 0;
}
