#include <iostream>
using namespace std;

int main()
{
    int test;
    int c[200000] = {0, };
    int e[200000] = {0, };
    int ccount, ecount;
    double csum = 0.f, esum = 0.f;
    double cavg, eavg;
    double tmp1, tmp2;
    int res = 0;
    
    cin >> test;
    while(test--)
    {
        cin >> ccount >> ecount;
        for(int i=0; i<ccount; i++)
        {
            cin >> c[i];
            csum += (double)c[i];
        }
        for(int i=0; i<ecount; i++)
        {
            cin >> e[i];
            esum += (double)e[i];
        }
        
        cavg = csum / (double)ccount;
        eavg = esum / (double)ecount;
        
        for(int i=0; i<ccount; i++)
        {
            tmp1 = (csum - c[i]) / (double)(ccount-1);
            tmp2 = (esum + c[i]) / (double)(ecount+1);
            
            if(tmp1 > cavg && tmp2 > eavg)
                res++;
        }
        
        cout << res << '\n';
        
        csum = 0.f;
        esum = 0.f;
        res = 0;
    }
    
    return 0;
}
