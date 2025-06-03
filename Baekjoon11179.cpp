#include <iostream>
#include <string>
using namespace std;

int main()
{
    unsigned int input;
    int mul = 1;
    string tmp;
    int res = 0;
    
    cin >> input;
    
    while(input)
    {
        tmp = to_string(input%2) + tmp;
        input /= 2;
    }
    
    for(int i=0; i<tmp.length(); ++i)
    {
        res += ((tmp[i] - '0') * mul);
        mul *= 2;
    }
    
    cout << res;
    
    return 0;
}
