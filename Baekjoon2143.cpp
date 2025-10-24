#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long len, t, tmp;
    vector<long long> a, b, asum, bsum;
    vector<long long>::iterator iter1, iter2;
    long long res = 0;
    
    cin >> t;
    
    cin >> len;
    a.resize(len, 0);
    for(int i=0; i<len; ++i)
        cin >> a[i];

    for(int i=0; i<len; ++i)
    {
        tmp = a[i];
        asum.push_back(tmp);
        for(int j=i+1; j<len; ++j)
        {
            tmp += a[j];
            asum.push_back(tmp);
        }
    }
    
    cin >> len;
    b.resize(len, 0);
    for(int i=0; i<len; ++i)
        cin >> b[i];
    
    for(int i=0; i<len; ++i)
    {
        tmp = b[i];
        bsum.push_back(tmp);
        for(int j=i+1; j<len; ++j)
        {
            tmp += b[j];
            bsum.push_back(tmp);
        }
    }
    
    sort(bsum.begin(), bsum.end());
    a.clear();
    b.clear();
    
    for(int i=0; i<asum.size(); ++i)
    {
        iter1 = lower_bound(bsum.begin(), bsum.end(), t-asum[i]);
        iter2 = upper_bound(bsum.begin(), bsum.end(), t-asum[i]);
        
        if(bsum.end() != iter1 && t-asum[i] == *iter1)
        {
            if(bsum.end() == iter2)
                res += (bsum.size() - (iter1 - bsum.begin()));
            else
                res += ((iter2 - bsum.begin()) - (iter1 - bsum.begin()));
        }
    }
    
    cout << res;
    
    return 0;
}
