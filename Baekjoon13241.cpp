#include <iostream>
using namespace std;

typedef long long int LLI;

LLI func(LLI a, LLI b)
{
    if(b == 0)
        return a;
    return func(b, a%b);
}

int main()
{
    LLI n1, n2;
    LLI tmp1, tmp2;
    cin >> n1 >> n2;
    
    tmp1 = (n1 > n2 ? n1 : n2);
    tmp2 = (n1 < n2 ? n1 : n2);
    
    cout << (n1 * n2 /func(tmp1, tmp2));
    
    return 0;
}
