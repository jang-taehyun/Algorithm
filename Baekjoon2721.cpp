#include <iostream>
using namespace std;

int t[302];
int w[301];
int test;
int idx;

int main()
{
    t[1] = 1;
    for(int i=2; i<=301; i++)
        t[i] = t[i-1] + i;
    
    w[1] = 1 * t[2];
    for(int i=2; i<=300; i++)
        w[i] = w[i-1] + (i * t[i+1]);
    
    cin >> test;
    while(test--)
    {
        cin >> idx;
        cout << w[idx] << '\n';
    }
    
    return 0;
}
