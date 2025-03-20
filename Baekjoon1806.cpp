#include <iostream>
using namespace std;

int main()
{
    int len, target;
    int arr[100000];
    int sum = 0, start = 0, end = 0;
    int tmp1, tmp2;
    int res = 0;
    
    cin >> len >> target;
    for(int i=0; i<len; ++i)
        cin >> arr[i];

    sum = arr[0];
    while(1)
    {
        // end가 len을 넘어가면, loop 종료
        if(end >= len)
            break;
        
        // sum이 target보다 크거나 같은 경우, res 갱신
        if(sum >= target)
        {
            if(res)
            {
                tmp1 = end - start + 1;
                res = (res > tmp1 ? tmp1 : res);
            }
            else
                res = end - start + 1;
        }
        
        // start 위치에 있는 수를 빼는 경우와,
        // end+1 위치에 있는 수를 더하는 경우 중
        // target에 더 가까운 경우로 선택
        if(end+1 < len)
        {
            tmp1 = sum - arr[start];
            tmp2 = sum + arr[end+1];
            
            // start 위치에 있는 수를 빼는 경우
            if(abs(target - tmp1) < abs(target - tmp2))
            {
                sum -= arr[start];
                ++start;
            }
            // end 위치에 있는 수를 더하는 경우
            else
            {
                ++end;
                sum += arr[end];
            }
        }
        // 만약 end+1이 len을 넘어가면,
        // start 위치에 있는 수를 뺀다.
        else
        {
            sum -= arr[start];
            ++start;
        }
        
        // 만약 start와 end의 위치가 역전됬다면, 서로 바꿔준다.
        if(start > end)
        {
            tmp1 = start;
            start = end;
            end = tmp1;
        }
    }
    
    cout << res;
    
    return 0;
}
