#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    cin >> input;
    
    if("NLCS" == input)
        cout << "North London Collegiate School";
    else if("BHA" == input)
        cout << "Branksome Hall Asia";
    else if("KIS" == input)
        cout << "Korea International School";
    else
        cout << "St. Johnsbury Academy";
    
    return 0;
}
