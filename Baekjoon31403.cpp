#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b, c;
    string sa, sb;
    
    cin >> a >> b >> c;
    
    cout << (a+b-c) << '\n';
    
    sa = to_string(a);
    sb = to_string(b);
    
    cout << (stoi((sa+sb)) - c) << '\n';
    
    return 0;
}
