#include <iostream>
#include <string>
using namespace std;

bool IsNotPrimary[1041];

int main()
{
    string input;
    int res=0;
    
    for(int i=2; i<1041; i++)
        if(!IsNotPrimary[i])
            for(int j=i*i; j<1041; j+=i)
                IsNotPrimary[j] = true;
    
    cin >> input;
    for(int i=0; i<input.length(); i++)
    {
        if(input[i] >= 'A' && input[i] <= 'Z')
            res += ((input[i] - 'A') + 27);
        else
            res += ((input[i] - 'a') + 1);
    }
    
    cout << (!IsNotPrimary[res] ? "It is a prime word." : "It is not a prime word.");
    
    return 0;
}
