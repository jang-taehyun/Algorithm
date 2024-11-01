#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int res = 0;
    
    while(getline(cin, input))
        res++;
    
    cout << res;
    
    return 0;
}
