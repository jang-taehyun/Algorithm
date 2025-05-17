#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int len;
    char input[100001] = {0, };
    
    cin >> len >> input;
    
    for(int i=len-5; i<len; ++i)
        cout << input[i];
    
    return 0;
}
