#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int test;
    string input1, input2;
    int a[26];
    int b[26];
    int res = 0;
    
    cin >> test;
    cin.ignore();
    
    for(int i=1; i<=test; i++)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        res = 0;
        
        getline(cin, input1);
        getline(cin, input2);
        
        for(int j=0; j<input1.length(); j++)
            a[input1[j] - 'a']++;
        for(int j=0; j<input2.length(); j++)
            b[input2[j] - 'a']++;
        
        for(int j=0; j<26; j++)
            if(a[j] != b[j])
                res += abs(a[j] - b[j]);
        
        cout << "Case #" << i << ": " << res << '\n';
    }
    
    return 0;
}
