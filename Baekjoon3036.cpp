#include <iostream>
using namespace std;

inline int MAXNUM(int a, int b) { return (a > b ? a : b); }
inline int MINNUM(int a, int b) { return (a < b ? a : b); }

int GCD(int n1, int n2)
{
    if(!n2)
        return n1;
    
    return GCD(n2, n1%n2);
}

int main()
{
    int cnt;
    int arr[100] = { 0, };
    int tmp1, tmp2, gcd;
    
    cin >> cnt;
    for(int i=0; i<cnt; ++i)
        cin >> arr[i];
    
    for(int i=1; i<cnt; ++i)
    {
        tmp1 = MAXNUM(arr[0], arr[i]);
        tmp2 = MINNUM(arr[0], arr[i]);
        gcd = GCD(tmp1, tmp2);
        
        cout << (arr[0] / gcd) << '/' << (arr[i] / gcd) << '\n';
    }
    
    return 0;
}
