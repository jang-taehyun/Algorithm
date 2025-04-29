#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int test;
    string input;
    string res;
    
    cin >> test;
    cin.ignore();
    for(int i=1; i<=test; ++i)
    {
        getline(cin, input);
        
        cout << "Case #" << i << ": ";
        for(int j=input.length()-1; j>=-1; --j)
        {
            if(-1 == j || ' ' == input[j])
            {
                reverse(res.begin(), res.end());
                cout << res << ' ';
                res = "";
            }
            else
                res += input[j];
        }
        cout << '\n';
        
        res = "";
    }
    
    return 0;
}
