#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int res=0;
    
    cin >> input;
    for(int i=0; i<input.length(); i++)
    {
        if(input[i] >= 'A' && input[i] <= 'Z')
        {
            if(i % 4)
            {
                input.insert(input.begin() + i, '0');
                res++;
            } 
        }
    }
    
    cout << res;
    
    return 0;
}
