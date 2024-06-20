#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string n1, n2, res2;
    int res1;
    cin >> n1 >> n2;
    
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());
    
    res1 = stoi(n1) + stoi(n2);
    res2 = to_string(res1);
    
    reverse(res2.begin(), res2.end());
    res1 = stoi(res2);
    res2 = to_string(res1);
    
    cout << res2;
    
    return 0;
}
