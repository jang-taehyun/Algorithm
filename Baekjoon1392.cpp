#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int res[10001];
    int n1, n2;
    int tmp, idx=0;
    
    cin >> n1 >> n2;
    
    for(int i=1; i<=n1; i++)
    {
        cin >> tmp;
        
        for(int j=0; j<tmp; j++)
            res[idx++] = i;
    }
    
    for(int i=0; i<n2; i++)
    {
        cin >> tmp;
        cout << res[tmp] << '\n';
    }
    
    return 0;
}
