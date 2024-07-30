#include <iostream>
using namespace std;

int main()
{
    int day, month, year;
    int res=0;
    
    while(1)
    {
        cin >> day >> month >> year;
        if(!day && !month && !year)
            break;
        
        for(int i=1; i<=month; i++)
        {
            if(month != i)
            {
                switch(i)
                {
                    case 2:
                        {
                            if(!(year % 4))
                            {
                                if(!(year % 100))
                                {
                                    if(!(year % 400))
                                        res += 29;
                                    else
                                        res += 28;
                                }
                                else
                                    res += 29;
                            }
                            else
                                res += 28;
                        }
                        break;
                    case 4: case 6: case 9: case 11:
                        res += 30;
                        break;
                    default:
                        res += 31;
                        break;
                }
            }
            else
                res += day;
        }
        
        cout << res << '\n';
        
        res=0;
    }
    
    return 0;
}
