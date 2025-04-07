#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int test;
    char input[1001] = {0, };
    
    cin >> test;
    while(test--)
    {
        cin >> input;
        cout << input[0] << input[strlen(input)-1] << '\n';
    }
    
    return 0;
}
