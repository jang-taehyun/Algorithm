#include <iostream>
using namespace std;

typedef long long LL;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    LL count, input, prev, sum=0;
    int flowcount=0;
    
    for(int i=0; i<3; i++)
    {
        sum=0;
        flowcount=0;
        
        cin >> count;
        
        for(int j=0; j<count; j++)
        {
            cin >> input;
            
            prev = sum;
            sum += input;
            
            if(prev < 0 && input < 0 && sum > 0)
                flowcount--;
            if(prev > 0 && input > 0 && sum < 0)
                flowcount++;
        }
        
        if(flowcount > 0)
            cout << '+' << '\n';
        else if(flowcount < 0)
            cout << '-' << '\n';
        else
        {
            if(sum)
                cout << (sum > 0 ? '+' : '-') << '\n';
            else
                cout << '0' << '\n';
        }
    }
    
    return 0;
}
