#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool IsFBI[5];
    bool IsEmpty=true;
    string input;
    
    for(int i=0; i<5; i++)
    {
        cin >> input;
        
        if(string::npos != input.find("FBI"))
        {
            IsFBI[i] = true;
            IsEmpty = false;
        }   
        else
            IsFBI[i] = false;
    }
    
    if(IsEmpty)
        cout << "HE GOT AWAY!";
    else
    {
        for(int i=0; i<5; i++)
            if(IsFBI[i])
                cout << i+1 << ' ';
    }
    
    return 0;
}
