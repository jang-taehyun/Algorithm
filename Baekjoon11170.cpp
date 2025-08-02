#include <iostream>
using namespace std;

int arr[1000001] = {0, };

int main()
{
    int cnt;
    int s, e;
    int sum=0, tmp;
    
    arr[0] = 1;
    for(int i=1; i<1000001; ++i)
    {
        sum = i;
        
        while(sum)
        {
            tmp = sum % 10;
            sum /= 10;
            
            if(!tmp)
                arr[i]++;
        }
    }
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> s >> e;
        
        sum=0;
        for(int i=s; i<=e; ++i)
            sum += arr[i];
        
        cout << sum << '\n';
    }
    
    return 0;
}
