#include <iostream>
#include <string>
using namespace std;

int main()
{
    int test;
    string input;
    string tmp;
    int res = 0;
    
    cin >> test;
    while(test--)
    {
        cin >> input;
        
        for(int i=2; i<input.length(); ++i)
            tmp += input[i];
        
        if(stoi(tmp) <= 90)
            ++res;
        tmp = "";
    }
    
    cout << res;
    
    return 0;
}
