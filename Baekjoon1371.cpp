#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ULL;

ULL alpha[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    char input;
    ULL Maxidx=0;
    vector<char> res;
    
    while(cin >> input)
    {
        if(input >= 'a' && input <= 'z')
            alpha[input - 'a']++;
    }
    
    for(int i=0; i<26; i++)
    {
        if(alpha[Maxidx] < alpha[i])
        {
            Maxidx = i;
            res.clear();
            res.push_back(i + 'a');
        }
        else if(alpha[Maxidx] == alpha[i])
        {
            res.push_back(i + 'a');
        }
    }
    
    for(int i=0; i<res.size(); i++)
        cout << res[i];
    
    return 0;
}
