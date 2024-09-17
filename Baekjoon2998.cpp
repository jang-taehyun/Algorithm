#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int res=0;
    
    cin >> input;
    while(input.length() % 3)
        input = "0" + input;
    
    for(int i=0; i<input.length(); i+=3)
    {
        res=0;
        
        if(input[i] == '1')
            res += 4;
        if(input[i+1] == '1')
            res += 2;
        if(input[i+2] == '1')
            res += 1;
        
        cout << res;
    }
    
    return 0;
}
