#include <iostream>
#include <string>
using namespace std;

int main()
{
    int test;
    string input1, input2;
    
    cin >> test;
    cin.ignore();
    
    while(test--)
    {
        cin >> input1 >> input2;
        
        cout << "Distances:";
        for(int i=0; i<input1.length(); i++)
        {
            if(input2[i] >= input1[i])
                cout << ' ' << (input2[i] - input1[i]);
            else
                cout << ' ' << ((input2[i] + 26) - input1[i]);
        }
        
        cout << '\n';
    }
    
    return 0;
}
