#include <iostream>
using namespace std;

inline int MAX(int n1, int n2) { return (n1 > n2 ? n1 : n2); }
inline int MIN(int n1, int n2) { return (n1 < n2 ? n1 : n2); }

int GCD(int a, int b)
{
    if(b == 0)
        return a;
    
    return GCD(b, a%b);
}

int main()
{
    int n1, n2, a1, a2;
    int gcd, lcm;
    int tmp1, tmp2;
    
    cin >> n1 >> n2 >> a1 >> a2;
    
    gcd = GCD(MAX(n2, a2), MIN(n2, a2));
    lcm = n2 * a2 / gcd;
    
    n1 *= (lcm / n2);
    a1 *= (lcm / a2);
    
    tmp1 = (n1 + a1);
    tmp2 = lcm;
    
    gcd = GCD(MAX(tmp1, tmp2), MIN(tmp1, tmp2));
    
    tmp1 /= gcd;
    tmp2 /= gcd;
    
    cout << tmp1 << ' ' << tmp2;
    
    return 0;
}
