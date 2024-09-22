#include <iostream>
using namespace std;

int main()
{
    char w[7][20]={"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};
    int n,m;
    int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    cin >> m >> n;
    for(int i=0; i<n-1; i++)
        m+=mon[i];
    
    cout << w[m%7];
    
    return 0;
}
