#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int cnt;
    string input1, input2;
    string tmp1, tmp2;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> input1 >> input2;
        
        tmp1 = input1;
        tmp2 = input2;
        
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        
        cout << input1 << " & " << input2;
        cout << (tmp1 == tmp2 ? " are anagrams." : " are NOT anagrams.");
        cout << '\n';
    }
    
    return 0;
}
