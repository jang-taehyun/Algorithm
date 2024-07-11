#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int res=0;
    int num;
    string tmp;
    
    cin >> input;
    input += ":";
    
    for(int i=0; i<input.length(); i+=3)
    {
        tmp = input[i];
        tmp += input[i+1];
        num = stoi(tmp);
        
        if(num >= 60)
        {
            res = 0;
            break;
        }
        if(num >= 1 && num <= 12)
            res += 2;
    }
    
    cout << res;
    
    return 0;
}
