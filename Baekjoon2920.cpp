#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int tmp;
    
    for(int i=0; i<8; i++)
    {
        cin >> tmp;
        input += to_string(tmp);
    }
    
    if("12345678" == input)
        cout << "ascending";
    else if("87654321" == input)
        cout << "descending";
    else
        cout << "mixed";
    
    return 0;
}
