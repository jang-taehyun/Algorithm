#include <iostream>
#include <string>
using namespace std;

int main()
{
    int test;
    string input;
    
    cin >> test;
    cin.ignore();
    
    while(test--)
    {
        cin >> input;
        
        for(int i=0; i<input.length(); i++)
        {
            if(input[i] >='A' && input[i] <= 'Z')
                cout << (char)(input[i] + ('a' - 'A'));
            else
                cout << input[i];
        }
        
        cout << '\n';
    }
    
    return 0;
}
