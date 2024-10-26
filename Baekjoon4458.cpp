#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int test;
    
    cin >> test;
    cin.ignore();
    
    while(test--)
    {
        getline(cin, input);
        
        if(input[0] >= 'a' && input[0] <= 'z')
            input[0] -= ('a' - 'A');
        
        cout << input << '\n';
    }
    
    return 0;
}
