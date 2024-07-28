#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tmp;
    int age, weight;
    
    while(1)
    {
        cin >> tmp;
        cin >> age >> weight;
        
        if("#" == tmp && !age && !weight)
            break;
        
        if(age > 17 || weight >= 80)
            tmp = tmp + " " + "Senior";
        else
            tmp = tmp + " " + "Junior";
        
        cout << tmp << '\n';
    }  
    
    return 0;
}
