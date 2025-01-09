#include <iostream>
#include <string>
using namespace std;

int main()
{
    int count;
    char input[50];
    int res = 1;
    
    cin >> count >> input;
    
    for(int i=0; i<count; i++)
    {
        if('L' == input[i])
            i++;
        res++;
    }
    
    if(res > count)
        res--;
    
    cout << res;
    
    return 0;
}
