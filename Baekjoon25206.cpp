#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char lecture[51] = {0, };
    double score;
    char grade[3] = {0, };
    
    double sum1 = 0.f;
    double sum2 = 0.f;
    
    for(int i=0; i<20; ++i)
    {
        cin >> lecture >> score >> grade;
        
        if(!strcmp("P", grade))
            continue;
        
        sum1 += score;
        
        if(!strcmp("A+", grade))
            sum2 += (score * 4.5);
        else if(!strcmp("A0", grade))
            sum2 += (score * 4.0);
        else if(!strcmp("B+", grade))
            sum2 += (score * 3.5);
        else if(!strcmp("B0", grade))
            sum2 += (score * 3.0);
        else if(!strcmp("C+", grade))
            sum2 += (score * 2.5);
        else if(!strcmp("C0", grade))
            sum2 += (score * 2.0);
        else if(!strcmp("D+", grade))
            sum2 += (score * 1.5);
        else if(!strcmp("D0", grade))
            sum2 += (score * 1.0);
    }
    
    cout << sum2 / sum1;
    
    return 0;
}
