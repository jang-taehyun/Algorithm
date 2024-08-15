#include <iostream>
using namespace std;

int n[101];

int main()
{
    int input;
    int res1=0, res2=0;
    
    for(int i=0; i<10; i++)
    {
        cin >> input;
        
        res1 += input;
        n[input / 10]++;
    }
    
    for(int i=1; i<101; i++)
        if(n[i] > n[res2])
            res2 = i;
    
    res1 /= 10;
    res2 *= 10;
        
    cout << res1 << '\n' << res2;
    
    return 0;
}
