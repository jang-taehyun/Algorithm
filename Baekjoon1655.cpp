#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len;
    priority_queue<int> minq;
    priority_queue<int, vector<int>, greater<int>> maxq;
    int mid, input;
    
    cin >> len;
    
    // 첫 번째
    cin >> input;
    cout << input << '\n';
    mid = input;
    
    // 2번째 부터
    for(int i=2; i<=len; ++i)
    {
        cin >> input;
        
        if(input > mid)
            maxq.push(input);
        else
            minq.push(input);
        
        while(1)
        {
            if(!(i%2) && maxq.size() - minq.size() == 1)
                break;
            if((i%2) && maxq.size() == minq.size())
                break;
            
            if(maxq.size() > minq.size())
            {
                minq.push(mid);
                mid = maxq.top();
                maxq.pop();
            }
            else
            {
                maxq.push(mid);
                mid = minq.top();
                minq.pop();
            }
        }
        
        cout << mid << '\n';
    }
    
    return 0;
}
