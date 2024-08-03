#include <iostream>
#include <string>
using namespace std;

int main()
{
    int input;
    string tmp="";
    
    cin >> input;
    
    for(int i=1; i<=input; i++)
        tmp += to_string(i);
    
    cout << tmp.find(to_string(input))+1;
    
    return 0;
}
