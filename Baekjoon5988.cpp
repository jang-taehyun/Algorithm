#include <iostream>
#include <string>
using namespace std;

int main()
{
    int test;
    int tmp;
    string input;
    
    cin >> test;
    cin.ignore();
    
    while(test--)
    {
        cin >> input;
        
        tmp = input[input.length() - 1] - '0';
        
        if(!(tmp % 2))
            cout << "even" << '\n';
        else
            cout << "odd" << '\n';
    }
    
    return 0;
}
