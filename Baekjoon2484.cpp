#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int num[6];
    int len;
    int res=0;
    int tmp1, tmp2, tmp3;
    
    cin >> len;
    while(len--)
    {
        memset(num, 0, sizeof(num));
        
        for(int i=0; i<4; i++)
        {
            cin >> tmp1;
            num[tmp1-1]++;
        }
        
        tmp1 = -1;
        tmp2 = -1;
        for(int i=0; i<6; i++)
        {
            if(num[i] == 4)
            {
                tmp1 = i;
                break;
            }
            else if(num[i] == 3)
            {
                tmp1 = i;
                break;
            }
            else if(num[i] == 2)
            {
                if(tmp1 != -1)
                {
                    tmp2 = i;
                    break;
                }
                else
                {
                    tmp1 = i;
                }
            }
        }
        
        if(tmp1 == -1 && tmp2 == -1)
        {
            for(int i=0; i<6; i++)
                if(num[i])
                    tmp1 = i;
            
            tmp3 = (tmp1+1) * 100;
        }
        else
        {
            if(num[tmp1] == 4)
                tmp3 = 50000 + ((tmp1+1) * 5000);
            else if(num[tmp1] == 3)
                tmp3 = 10000 + ((tmp1+1) * 1000);
            else
            {
                if(tmp2 == -1)
                    tmp3 = 1000 + ((tmp1+1) * 100);
                else
                    tmp3 = 2000 + ((tmp1+1) * 500) + ((tmp2+1) * 500);
            }
        }
        
        if(res < tmp3)
            res = tmp3;
    }
    
    cout << res;
    
    return 0;
}
