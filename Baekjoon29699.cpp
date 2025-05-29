#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[] = "WelcomeToSMUPC";
    int n;
    
    cin >> n;
    cout << str[(n-1)%strlen(str)];
    
    return 0;
}
