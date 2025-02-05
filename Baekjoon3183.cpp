#include <iostream>
using namespace std;

int main()
{
    int day, month, year;
    bool IsValid = true;
    
    while(1)
    {
        cin >> day >> month >> year;
        
        if(!day && !month && !year)
            break;
        
        if(month == 2)
        {
            if(!(year % 400) || (!(year % 4) && (year % 100)))
            {
                if(!(day >= 1 && day <= 29))
                    IsValid = false;
            }
            else
            {
                if(!(day >=1 && day <= 28))
                    IsValid = false;
            }
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            if(!(day >= 1 && day <= 30))
                IsValid = false;
        }
        else
        {
            if(!(day >= 1 && day <= 31))
                IsValid = false;
            if(!(month >= 1 && month <= 12))
                IsValid = false;
        }
        
        cout << (IsValid ? "Valid" : "Invalid") << '\n';
        IsValid = true;
    }
    
    return 0;
}
