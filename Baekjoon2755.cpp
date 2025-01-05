#include <iostream>
#include <string>
using namespace std;

int main()
{
    int count;
    string subject, grade;
    int credit;
    int AllCredit = 0;
    double sum = 0.f;
    double tmp;
    
    cout.precision(2);
    cout << fixed;
    
    cin >> count;
    for(int i=0; i<count; i++)
    {
        cin >> subject >> credit >> grade;
        
        AllCredit += credit;
        
        if('A' == grade[0])
            tmp = 4.f;
        else if('B' == grade[0])
            tmp = 3.f;
        else if('C' == grade[0])
            tmp = 2.f;
        else if('D' == grade[0])
            tmp = 1.f;
        
        if('F' == grade[0])
            tmp = 0.f;
        else if('+' == grade[1])
            tmp += 0.3f;
        else if('-' == grade[1])
            tmp -= 0.3f;
        
        sum += ((double)credit * tmp);
    }
    
    cout << (sum / (double)AllCredit);
    
    return 0;
}
