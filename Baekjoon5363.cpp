#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input, last;
    int test;
    int count = 0;
    
    cin >> test;
    cin.ignore();
    
    while(test--)
    {
        getline(cin, input);
        
        while(count < 2)
        {
            last += input[0];
            input.erase(input.begin());
            
            if(input[0] == ' ')
                count++;
        }
        input.erase(input.begin());
        
        cout << input << ' ' << last << '\n';
        
        input.clear();
        last.clear();
        count = 0;
    }
    
    return 0;
}
