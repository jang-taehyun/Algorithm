#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    cin >> input;
    
    if("A+" == input)
        cout << "4.3";
    else if("A0" == input)
        cout << "4.0";
    else if("A-" == input)
        cout << "3.7";
    else if("B+" == input)
        cout << "3.3";
    else if("B0" == input)
        cout << "3.0";
    else if("B-" == input)
        cout << "2.7";
    else if("C+" == input)
        cout << "2.3";
    else if("C0" == input)
        cout << "2.0";
    else if("C-" == input)
        cout << "1.7";
    else if("D+" == input)
        cout << "1.3";
    else if("D0" == input)
        cout << "1.0";
    else if("D-" == input)
        cout << "0.7";
    else if("F" == input)
        cout << "0.0";
    
    
    return 0;
}
