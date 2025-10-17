#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len, bound, cnt, coupon;
    vector<int> arr;
    vector<int> cnts;
    unordered_map<int, int> tmp;
    unordered_map<int, int>::iterator iter;
    int left=1, right, mid, idx=0, comp, res=1;
    
    cin >> len >> bound >> cnt >> coupon;
    
    arr.resize(len, 0);
    cnts.resize(bound+1, 0);
    for(int i=0; i<len; ++i)
    {
        cin >> arr[i];
        ++cnts[arr[i]];
    }
    
    right = cnt + 1;
    while(left <= right)
    {
        mid = (left + right) / 2;
        
        // map 초기화 //
        // cnt 개의 초밥 먹기
        for(int i=0; i<cnt; ++i)
        {
            iter = tmp.find(arr[i]);
            if(tmp.end() == iter)
                tmp.insert(make_pair(arr[i], 1));
            else
                ++(iter->second);
        }
        
        comp = tmp.size();
        iter = tmp.find(coupon);
        if(tmp.end() == iter)
            ++comp;
        
        // map을 초기화할 때 mid 가지의 초밥을 먹는 경우가 아닌 경우
        if(comp < mid)
        {
            for(int i=1; i<len; ++i)
            {
                // 현재 초밥 추가
                idx = (i + cnt - 1) % len;
                iter = tmp.find(arr[idx]);
                
                if(tmp.end() == iter)
                    tmp.insert(make_pair(arr[idx], 1));
                else
                    ++(iter->second);
                
                // 이전 초밥 없애기
                iter = tmp.find(arr[i-1]);
                --(iter->second);
                
                if(!(iter->second))
                    tmp.erase(iter);
                
                comp = tmp.size();
                iter = tmp.find(coupon);
                if(tmp.end() == iter)
                    ++comp;
                
                // 현재까지 먹은 초밥의 종류(comp)가 mid보다 크거나 같다면, break
                if(comp >= mid)
                    break;
            }
        }
        
        if(comp >= mid)
        {
            left = mid + 1;
            res = (comp > res ? comp : res);
        }
        else
            right = mid - 1;
        
        tmp.clear();
    }
    
    cout << res;
    
    return 0;
}
