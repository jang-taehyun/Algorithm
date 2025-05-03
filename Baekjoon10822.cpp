#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input, tmp;
    int sum = 0;
    
    getline(cin, input);
    for(int i=0; i<input.length(); ++i)
    {
        if(input[i] == ',')
        {
            sum += stoi(tmp);
            tmp = "";
        }
        else
            tmp += input[i];
    }
    sum += stoi(tmp);
    
    cout << sum;
    
    return 0;
}
