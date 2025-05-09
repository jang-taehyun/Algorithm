#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cmp;
    int cnt;
    string input;
    int res = 0;
    
    cin >> cmp >> cnt;
    while(cnt--)
    {
        cin >> input;
        
        input += input;
        if(input.find(cmp) != string::npos)
            ++res;
    }
    
    cout << res;
    
    return 0;
}
