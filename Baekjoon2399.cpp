#include <iostream>
#include <cstdlib>
using namespace std;

typedef unsigned long long ULL;

int main()
{
    ULL arr[10000] = {0, };
    ULL len;
    long long tmp;
    ULL res = 0;
    
    cin >> len;
    for(int i=0; i<len; i++)
        cin >> arr[i];
    
    for(int i=0; i<len-1; i++)
    {
        for(int j=i; j<len; j++)
        {
            tmp = abs((long long)arr[i] - (long long)arr[j]);
            res += (ULL)tmp;
        }
    }
    
    res *= 2;
    
    cout << res;
    
    return 0;
}
