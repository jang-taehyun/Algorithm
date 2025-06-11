#include <iostream>
using namespace std;

int main()
{
    int bucket[101] = {0, };
    int cnt;
    int len;
    int s, e, input;
    
    cin >> len >> cnt;
    while(cnt--)
    {
        cin >> s >> e >> input;
        
        for(int i=s; i<=e; ++i)
            bucket[i] = input;
    }
    
    for(int i=1; i<=len; ++i)
        cout << bucket[i] << ' ';
    
    return 0;
}
