#include <iostream>
using namespace std;

int main()
{
    int o, w;
    double so, eo;
    char c;
    int n;
    int cnt = 1;
    
    while(1)
    {
        cin >> o >> w;
        
        if(!o && !w)
            break;
        
        so = (double)o * 0.5f;
        eo = (double)o * 2.f;
        
        while(1)
        {
            cin >> c >> n;
            
            if('#' == c && !n)
                break;
            if(w <= 0)
                continue;
            
            if('F' == c)
                w += n;
            else if('E' == c)
                w -= n;
        }
        
        cout << cnt << ' ';
        if(w <= 0)
            cout << "RIP" << '\n';
        else if(so < (double)w && (double)w < eo)
            cout << ":-)" << '\n';
        else
            cout << ":-(" << '\n';
        
        cnt++;
    }
    
    return 0;
}
