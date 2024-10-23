#include <iostream>
using namespace std;

int main()
{
    int input;
    int tmp;
    
    while(1)
    {
        cin >> input;
        if(!input)
            break;
        
        while(1)
        {
            cout << input << ' ';
            
            if(input < 10)
                break;
            
            tmp = 1;
            while(input)
            {
                tmp *= (input % 10);
                input /= 10;
            }
            
            input = tmp;
        }
        
        cout << '\n';
    }
    
    return 0;
}
