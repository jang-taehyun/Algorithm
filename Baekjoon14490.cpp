#include <iostream>
#include <string>
using namespace std;

int GCD(int a, int b)
{
    if(b == 0)
        return a;  
    return GCD(b, a%b);
}

int main()
{
    string input, tmp;
    int a=0, b=0, div, n1, n2;
    
    cin >> input;
    for(int i=0; i<input.length(); ++i)
    {
        if(input[i] == ':')
        {
            a = stoi(tmp); 
            tmp = "";
        }
        else if(i == input.length()-1)
        {
            tmp += input[i];
            b = stoi(tmp);
        }
        else
            tmp += input[i];
    }
    
    n1 = (a > b ? a : b);
    n2 = (a < b ? a : b);
    div = GCD(n1, n2);
    
    cout << (a / div) << ':' << (b / div);
    
    return 0;
}
