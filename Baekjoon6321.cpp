#include <iostream>
#include <string>
using namespace std;

int main()
{
    int test;
    string input;
    
    cin >> test;
    cin.ignore();
    
    for(int i=1; i<=test; i++)
    {
        cin >> input;
        
        cout << "String #" << i << '\n';
        for(int i=0; i<input.length(); i++)
        {
            input[i]++;
            
            if(input[i] > 'Z')
                input[i] = 'A';
            
            cout << input[i];
        }
        cout << "\n\n";
    }
    
    return 0;
}
