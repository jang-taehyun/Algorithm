#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input;
    set<string> s;
    
    cin >> input;
    
    for(int i=0; i<input.length(); ++i)
        for(int j=i; j<input.length(); ++j)
            s.insert(input.substr(i, j-i+1));

    cout << s.size();
    
    return 0;
}
