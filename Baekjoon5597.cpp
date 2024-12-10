#include <iostream>
using namespace std;

bool IsSubmit[30];

int main()
{
    int input;
    
    for(int i=0; i<28; i++)
    {
        cin >> input;
        IsSubmit[input-1] = true;
    }
    
    for(int i=0; i<30; i++)
        if(!IsSubmit[i])
            cout << (i+1) << '\n';
    
    return 0;
}
