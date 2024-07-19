#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int test;
    string input;
    string minus="";
    int tmp1=0, tmp2=0;
    int mul=1;
    
    cin >> test;
    while(test--)
    {
        cin >> input;

        for(int i=2; i>=0; i--)
        {
            tmp1 += ((input[i] - 'A') * mul);
            mul *= 26;
        }
        
        for(int i=4; i<8; i++)
            minus += input[i];
        tmp2 = stoi(minus);
        
        cout << ((abs(tmp1 - tmp2) <= 100) ? "nice" : "not nice") << '\n';
        
        tmp1=0;
        tmp2=0;
        mul=1;
        minus="";
    }
    
    return 0;
}
