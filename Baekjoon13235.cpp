#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string input;
    string tmp;
    
    cin >> input;
    
    tmp = input;
    reverse(tmp.begin(), tmp.end());
    
    cout << (input == tmp ? "true" : "false");
    
    return 0;
}
