#include <iostream>
#include <vector>
#define BOUND 1000001
using namespace std;

typedef unsigned long long ULL;

bool IsNotPrimary[BOUND];

int main()
{
    int len;
    ULL input;
    vector<ULL> pri;
    bool flag;
    
    for(ULL i=2; i<BOUND; i++)
    {
        if(!IsNotPrimary[i])
        {
            pri.push_back(i);
            for(ULL j=i*i; j<BOUND; j+=i)
                IsNotPrimary[j] = true;
        }
    }
    
    cin >> len;
    while(len--)
    {
        flag = true;
        cin >> input;
        
        for(ULL i=0; i<pri.size(); i++)
            if(!(input % pri[i]))
            {
                flag = false;
                break;
            }
        
        cout << (flag ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
