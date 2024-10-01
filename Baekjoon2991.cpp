#include <iostream>
using namespace std;

bool a[1000];
bool b[1000];

int main()
{
    int a1, a2, b1, b2, arrive;
    bool IsAttack;
    int tmp;
    
    cin >> a1 >> a2 >> b1 >> b2;
    
    IsAttack = true;
    tmp = a1;
    for(int i=1; i<1000; i++)
    {
        if(IsAttack)
            a[i] = true;
        
        tmp--;
        
        if(!tmp)
        {
            tmp = (!IsAttack ? a1 : a2);
            IsAttack = !IsAttack;
        }
    }
    
    IsAttack = true;
    tmp = b1;
    for(int i=1; i<1000; i++)
    {
        if(IsAttack)
            b[i] = true;
        
        tmp--;
        
        if(!tmp)
        {
            tmp = (!IsAttack ? b1 : b2);
            IsAttack = !IsAttack;
        }
    }
    
    for(int i=0; i<3; i++)
    {
        cin >> arrive;
        
        tmp = 0;
        if(a[arrive])
            tmp++;
        if(b[arrive])
            tmp++;
        
        cout << tmp << '\n';
    }
    
    return 0;
}
