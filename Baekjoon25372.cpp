#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int test;
    char input[21] = {0, };
    
    cin >> test;
    while(test--)
    {
        cin >> input;
        
        if(6 <= strlen(input) && strlen(input) <= 9)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
    
    return 0;
}
