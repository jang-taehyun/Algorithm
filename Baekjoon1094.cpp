#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> len;
    int target;
    int cur = 64;
    int tmp1, tmp2, tmp3;
    
    cin >> target;
    
    len.push_back(cur);
    
    while(cur != target)
    {
        tmp1 = len[0];
        len.erase(len.begin());
        
        tmp2 = tmp1 / 2;
        tmp3 = tmp1 / 2;
        
        len.push_back(tmp2);
        if(cur - tmp3 >= target)
            cur -= tmp3;
        else
            len.push_back(tmp3);
        
        sort(len.begin(), len.end());
    }
    
    cout << len.size();
    
    return 0;
}
