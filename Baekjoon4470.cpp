#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string input;
    vector<string> res;
    int test;
    
    cin >> test;
    cin.ignore();
    
    for(int i=0; i<test; i++)
    {
        getline(cin, input);
        res.push_back(input);
    }
    
    for(int i=0; i<test; i++)
        cout << i+1 << ". " << res[i] << '\n';
    
    return 0;
}
