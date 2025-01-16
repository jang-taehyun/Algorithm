#include <iostream>
using namespace std;

typedef unsigned long long ULL;

int main()
{
    ULL FileCount;
    ULL FileSize[50] = {0, };
    ULL ClusterSize;
    ULL tmp1, tmp2;
    ULL res = 0;
    
    cin >> FileCount;
    for(ULL i=0; i<FileCount; i++)
        cin >> FileSize[i];
    cin >> ClusterSize;
    
    for(ULL i=0; i<FileCount; i++)
    {
        tmp1 = FileSize[i] / ClusterSize;
        tmp2 = FileSize[i] % ClusterSize;
        
        res += tmp1;
        
        if(tmp2)
            res++;
    }
    
    cout << (res * ClusterSize);
    
    return 0;
}
