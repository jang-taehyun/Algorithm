#include <iostream>
#include <string>
using namespace std;

int main()
{
    int test;
    string input;
    bool IsDoit = false;
    
    cin >> test;
    cin.ignore();
    
    while(test--)
    {
        cin >> input;
        
        for(int i=0; i<input.length() / 2; i++)
        {
            if(input[i] == input[input.length() - 1 - i])
                IsDoit = true;
            else
                IsDoit = false;
        }
        
        cout << (IsDoit ? "Do-it" : "Do-it-Not") << '\n';
    }
    
    return 0;
}
