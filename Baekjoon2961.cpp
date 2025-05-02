#include <iostream>
using namespace std;

int len;
int Acidity[10] = {0, };    // 신맛 -> x
int Acerbity[10] = {0, };   // 쓴맛 -> +
int res = 0x7f7f;
int Choose[10] = {0, };
bool IsChoose[10] = {false, };

void bf(int cur, int bound)
{
    if(cur >= bound)
    {
        int sum1 = 1, sum2 = 0, tmp;
        
        for(int i=0; i<cur; ++i)
        {
            sum1 *= Acidity[Choose[i]];
            sum2 += Acerbity[Choose[i]];
        }
        
        tmp = abs(sum1 - sum2);
        
        if(res > tmp)
            res = tmp;
        
        return;
    }
    
    for(int i=0; i<len; ++i)
    {
        if(!IsChoose[i])
        {
            IsChoose[i] = true;
            Choose[cur] = i;
            bf(cur+1, bound);
            IsChoose[i] = false;
        }
    }
}

int main()
{
    cin >> len;
    for(int i=0; i<len; ++i)
        cin >> Acidity[i] >> Acerbity[i];
    
    for(int i=1; i<=len; ++i)
        bf(0, i);
    
    cout << res;
    
    return 0;
}
