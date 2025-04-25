#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int comp1=0, comp2=0;
    
    for(int i=0; i<input.length()/2; ++i)
    {
        comp1 += (input[i] - '0');
        comp2 += (input[input.length()/2 + i] - '0');
    }
    
    cout << (comp1 == comp2 ? "LUCKY" : "READY");
    
    return 0;
}
