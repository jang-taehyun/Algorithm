#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string input, cmp;
    cin >> input >> cmp;
    
    cout << (strstr(input.c_str(), cmp.c_str()) == NULL ? 0 : 1);
    
    return 0;
}
