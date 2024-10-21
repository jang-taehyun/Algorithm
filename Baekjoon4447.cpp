#include <iostream>
#include <string>
using namespace std;

int main()
{
    int test;
    string input;
    int g=0, b=0;
    
    cin >> test;
    cin.ignore();
    
    while(test--)
    {
        getline(cin, input);
        
        for(int i=0; i<input.length(); i++)
        {
            if(input[i] == 'g' || input[i] == 'G')
                g++;
            if(input[i] == 'b' || input[i] == 'B')
                b++;
        }
        
        cout << input << " is ";
        if(g > b)
            cout << "GOOD";
        else if(g < b)
            cout << "A BADDY";
        else
            cout << "NEUTRAL";
        cout << '\n';
        
        g = 0;
        b = 0;
    }
    
    return 0;
}
