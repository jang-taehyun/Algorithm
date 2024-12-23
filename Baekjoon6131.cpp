#include <iostream>
using namespace std;

typedef unsigned int UINT;

int main()
{
    UINT n, a, b;
    UINT arr[501] = { 0, };
    int res = 0;
    
    for(UINT i=1; i<501; i++)
        arr[i] = i * i;
    
    cin >> n;
    
    for(int i=1; i<501; i++)
        for(int j=i; j<501; j++)
            if(arr[i] + n == arr[j])
            {
                res++;
                break;
            }
    
    cout << res;
    
    return 0;
}
