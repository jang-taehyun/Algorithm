#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test, len;
    vector<int> a, b;
    vector<int>::iterator iter;
    
    cin >> test;
    while(test--)
    {
        cin >> len;
        a.resize(len, 0);
        for(int i=0; i<len; ++i)
            cin >> a[i];

        cin >> len;
        b.resize(len, 0);
        for(int i=0; i<len; ++i)
            cin >> b[i];
        
        sort(a.begin(), a.end());
        for(int i=0; i<len; ++i)
        {
            iter = lower_bound(a.begin(), a.end(), b[i]);
            if(a.end() != iter && *iter == b[i])
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        
        a.clear();
        b.clear();
    }
    
    return 0;
}
