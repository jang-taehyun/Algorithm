#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int line, brand;
    int package[50] = {0, };
    int several[50] = {0, };
    int packageNum = 0;
    int tmp;
    int res = 100001;
    
    cin >> line >> brand;
    
    for(int i=0; i<brand; i++)
        cin >> package[i] >> several[i];
    
    if(line >= 6)
        packageNum = line / 6;
    
    sort(package, package+brand);
    sort(several, several+brand);
    
    tmp = package[0] * (packageNum + 1);
    if(res > tmp)
        res = tmp;
    
    tmp = package[0] * packageNum + several[0] * (line % 6);
    if(res > tmp)
        res = tmp;
    
    tmp = several[0] * line;
    if(res > tmp)
        res = tmp;
    
    cout << res;
    
    return 0;
}
