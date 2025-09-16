#include <iostream>
#include <string>
using namespace std;

int main()
{
    int cnt;
    string input;
    unsigned long long num, r=1;
    unsigned long long res = 0;
    
    cin >> cnt >> input;
    for(int i=0; i<cnt; ++i)
    {
        num = input[i] - 'a' + 1;
        
        res += (num * r) % 1234567891;
        res %= 1234567891;
        
        r = (r * 31) % 1234567891;
    }
    
    cout << res;
    
    return 0;
}
