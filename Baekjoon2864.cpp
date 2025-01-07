#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tmp1, tmp2;
    long long res1, res2;
    
    cin >> tmp1 >> tmp2;
    
    for(int i=0; i<tmp1.length(); i++)
        if('6' == tmp1[i])
            tmp1[i] = '5';
    for(int i=0; i<tmp2.length(); i++)
        if('6' == tmp2[i])
            tmp2[i] = '5';
    res1 = stoll(tmp1) + stoll(tmp2);
    
    for(int i=0; i<tmp1.length(); i++)
        if('5' == tmp1[i])
            tmp1[i] = '6';
    for(int i=0; i<tmp2.length(); i++)
        if('5' == tmp2[i])
            tmp2[i] = '6';
    res2 = stoll(tmp1) + stoll(tmp2);
    
    cout << res1 << ' ' << res2;
    
    return 0;
}
