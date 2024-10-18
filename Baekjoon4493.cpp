#include <iostream>
using namespace std;

int main()
{
    int test;
    
    int n;
    int res1 = 0, res2 = 0;
    char tmp1, tmp2;
    
    cin >> test;
    while(test--)
    {
        cin >> n;
        
        while(n--)
        {
            cin >> tmp1 >> tmp2;
            
            if(tmp1 == 'R')
            {
                if(tmp2 == 'P')
                    res2++;
                else if(tmp2 == 'S')
                    res1++;
            }
            else if(tmp1 == 'P')
            {
                if(tmp2 == 'S')
                    res2++;
                else if(tmp2 == 'R')
                    res1++;
            }
            else if(tmp1 == 'S')
            {
                if(tmp2 == 'R')
                    res2++;
                else if(tmp2 == 'P')
                    res1++;
            }
        }
        
        if(res1 > res2)
            cout << "Player 1" << '\n';
        else if(res1 < res2)
            cout << "Player 2" << '\n';
        else
            cout << "TIE" << '\n';
        
        res1 = 0;
        res2 = 0;
    }
    
    return 0;
}
