#include <iostream>
using namespace std;

int main()
{
    int len;
    int a=0, b=0;
    char input;
    
    cin >> len;
    for(int i=0; i<len; ++i)
    {
        cin >> input;
        input == 'A' ? a++ : b++;
    }
    
    if(a > b)
        cout << 'A';
    else if(a < b)
        cout << 'B';
    else
        cout << "Tie";
    
    return 0;
}
