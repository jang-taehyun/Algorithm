#include <iostream>
using namespace std;

int main()
{
    int bucket[101] = {0, };
    int len, cnt;
    int swap1, swap2;
    int tmp;
    
    cin >> len >> cnt;
    for(int i=1; i<=len; ++i)
        bucket[i] = i;
    
    while(cnt--)
    {
        cin >> swap1 >> swap2;
        
        tmp = bucket[swap1];
        bucket[swap1] = bucket[swap2];
        bucket[swap2] = tmp;
    }
    
    for(int i=1; i<=len; ++i)
        cout << bucket[i] << ' ';
    
    return 0;
}
