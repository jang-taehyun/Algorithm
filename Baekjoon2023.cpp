#include <iostream>
using namespace std;

int len;

bool IsPrime(int n)
{
    if(n < 2)
        return false;
    
    for(int i=2; i*i<=n; ++i)
        if(!(n % i))
            return false;
    
    return true;
}

void Backtracking(int cnt, int cur)
{
    if(cnt >= len)
    {
        cout << cur << '\n';
        return;
    }

    int tmp;
    for(int i=(cnt ? 0 : 1); i<10; ++i)
    {
        tmp = cur * 10 + i;
        if(IsPrime(tmp))
            Backtracking(cnt+1, tmp);
    }
}

int main()
{    
    cin >> len;
    Backtracking(0, 0);
    
    return 0;
}
