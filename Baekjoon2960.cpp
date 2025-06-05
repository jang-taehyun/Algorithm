#include <iostream>
using namespace std;

bool num[1001] = {false, };

int main()
{
    int n, k;
    int idx=0;
    bool IsFind = false;
    
    cin >> n >> k;
    for(int i=2; i<=n; ++i)
    {
        if(IsFind)
            break;
        if(num[i])
            continue;
        
        for(int j=i; j<=n; j+=i)
        {
            if(num[j])
                continue;
            
            num[j] = true;
            ++idx;
            
            if(k == idx)
            {
                cout << j;
                IsFind = true;
                break;
            }
        }
    }
    
    return 0;
}
