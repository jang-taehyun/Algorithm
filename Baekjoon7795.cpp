#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int test;
    int alen, blen;
    vector<int> a;
    vector<int> b;
    int left, right, mid, res=0;
    
    cin >> test;
    while(test--)
    {
        cin >> alen >> blen;
        
        a.resize(alen, 0);
        b.resize(blen, 0);
        for(int i=0; i<alen; ++i)
            cin >> a[i];
        for(int i=0; i<blen; ++i)
            cin >> b[i];
        
        sort(b.begin(), b.end());
        
        for(int i=0; i<alen; ++i)
            res += lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        
        cout << res << '\n';
        
        a.clear();
        b.clear();
        res = 0;
    }
    
    return 0;
}
