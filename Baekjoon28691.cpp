#include <iostream>
using namespace std;

int main()
{
    char input;
    cin >> input;
    
    switch(input)
    {
        case 'M':
            cout << "MatKor";
            break;
        case 'W':
            cout << "WiCys";
            break;
        case 'C':
            cout << "CyKor";
            break;
        case 'A':
            cout << "AlKor";
            break;
        case '$':
            cout << "$clear";
            break;
    }
    
    return 0;
}
