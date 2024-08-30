#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, idx;
    string input;
    
    cin >> n;
    while(n--)
    {
        cin >> idx;
        cin >> input;
        
        for(int i=0; i<input.length(); i++)
        {
            if(idx-1 != i)
                cout << input[i];
        }
        
        cout << endl;
    }
    
    return 0;
}