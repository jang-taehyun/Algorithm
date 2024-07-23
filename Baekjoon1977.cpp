#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int start, end;
    int min_res= -1, sum = 0;
    int tmp;
    
    cin >> start >> end;
    
    for(int i=1; i<101; i++)
    {
        tmp = pow(i, 2);
        if(tmp >= start && tmp <= end)
        {
            if(-1 == min_res)
                min_res = tmp;
            sum += tmp;
        }
    }
    
    if(-1 != min_res)
        cout << sum << '\n' << min_res;
    else
        cout << -1;
    
    return 0;
}
