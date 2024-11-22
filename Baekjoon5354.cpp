#include <iostream>
using namespace std;

int main()
{
    int test;
    int len;
    
    cin >> test;
    while(test--)
    {
        cin >> len;
        
        for(int i=0; i<len; i++)
        {
            for(int j=0; j<len; j++)
            {
                if(!i || !j || (i == len-1) || (j == len-1))
                    cout << '#';
                else
                    cout << 'J';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    
    return 0;
}
