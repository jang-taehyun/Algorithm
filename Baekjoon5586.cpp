#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    string tmp;
    int res1=0, res2=0;
    
    cin >> input;
    
    for(int i=0; i<input.length()-2; i++)
    {
        for(int j=i; j<i+3; j++)
            tmp += input[j];
        
        if("JOI" == tmp)
            res1++;
        else if("IOI" == tmp)
            res2++;
        
        tmp.clear();
    }
    
    cout << res1 << '\n' << res2;
    
    return 0;
}
