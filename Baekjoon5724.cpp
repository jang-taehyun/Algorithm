#include <iostream>
using namespace std;

int main()
{
    int res[101] = { 0, };
    int input;
    int idx = 1;
    
    res[0] = 0;
    res[1] = 1;
    
    while(1)
    {
        cin >> input;
        if(!input)
            break;
        
        if(input > idx)
        {
            for(int i=idx+1; i<=input; i++)
                res[i] = res[i-1] + (i * i);
            idx = input;
        }
        
        cout << res[input] << '\n';
    }
    
    return 0;
}
