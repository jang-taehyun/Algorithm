#include <iostream>
#include <string>
using namespace std;

int main()
{
    string res;
    int input;
    int test;
    
    cin >> test;
    while(test--)
    {
        cin >> input;
        
        while(input)
        {
            res += (to_string(input % 2));
            input /= 2;
        }
        
        for(int i=0; i<res.length(); i++)
            if(res[i] == '1')
                cout << i << ' ';
        cout << '\n';
        
        res.clear();
    }
    
    return 0;
}
