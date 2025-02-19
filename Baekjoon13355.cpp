#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int arrLen, bridgeLen, MaxWeight;
    queue<int> carWeight;
    queue<pair<int, int>> bridge;
    int curWeight = 0;
    int tmp;
    int res = 0;
    
    cin >> arrLen >> bridgeLen >> MaxWeight;
    for(int i=0; i<arrLen; i++)
    {
        cin >> tmp;
        carWeight.push(tmp);
    }
    
    while(1)
    {
        if(carWeight.empty() && bridge.empty())
            break;
        
        if(!bridge.empty() && res - bridge.front().second >= bridgeLen)
        {
            curWeight -= bridge.front().first;
            bridge.pop();
        }
            
        
        if(!carWeight.empty() && curWeight + carWeight.front() <= MaxWeight)
        {
            curWeight += carWeight.front();
            bridge.push(make_pair(carWeight.front(), res));
            carWeight.pop();
        }
        
        res++;
    }
    
    cout << res;
    
    return 0;
}
