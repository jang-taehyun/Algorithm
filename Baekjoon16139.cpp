#include <iostream>
#include <string>
using namespace std;

int arr[26][200000] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input;
    int cnt;
    char alpha;
    int s, e;
    
    cin >> input;
    
    arr[input[0] - 'a'][0] = 1;
    for(int i=1; i<input.length(); ++i)
    {
        for(int j=0; j<26; ++j)
        {
            arr[j][i] = arr[j][i-1];
            
            if((input[i] - 'a') == j)
                ++arr[j][i];
        }
    }
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> alpha >> s >> e;
        
        if(s)
            cout << (arr[alpha - 'a'][e] - arr[alpha - 'a'][s-1]) << '\n';
        else
            cout << arr[alpha - 'a'][e] << '\n';
    }
    
    return 0;
}
