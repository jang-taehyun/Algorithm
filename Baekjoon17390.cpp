#include <iostream>
#include <algorithm>
using namespace std;

int arr[300000] = { 0, };
int sum[300000] = { 0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len, cnt;
    int s, e;
    
    cin >> len >> cnt;
    for(int i=0; i<len; ++i)
        cin >> arr[i];
    
    sort(arr, arr+len);
    
    sum[0] = arr[0];
    for(int i=1; i<len; ++i)
    {
        sum[i] = arr[i];
        sum[i] += sum[i-1];
    }
    
    while(cnt--)
    {
        cin >> s >> e;
        
        --s;
        --e;
        
        if(s-1 >= 0)
            cout << (sum[e] - sum[s-1]) << '\n';
        else
            cout << sum[e] << '\n';
    }
    
    return 0;
}
