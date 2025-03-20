#include <iostream>
using namespace std;

int main()
{
    int arr[10000];
    int n, m;
    int sum = 0;
    int start = 0, end = 0;
    int res = 0;
    
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> arr[i];
    
    sum = arr[0];
    while(end < n && start < n)
    {
        // sum이 m보다 작을 경우, end 증가
        if(sum < m)
        {
            ++end;
            
            if(end  < n)
                sum += arr[end];
        }
        // sum이 m보다 클 경우, start 증가
        else if(sum > m)
        {
            sum -= arr[start];
            ++start;
        }
        // sum이 m이랑 같을 경우, start 증가
        else
        {
            ++res;
            
            sum -= arr[start];
            ++start;
        }
    }
    
    cout << res;
    
    return 0;
}
