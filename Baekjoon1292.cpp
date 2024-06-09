#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<unsigned int> numbers;
    int start, end;
    unsigned int res = 0;
    
    for(int i=1; i<=1000; i++)
        for(int j=0; j<i; j++)
            numbers.push_back(i);
    
    cin >> start >> end;
    for(int i=start-1; i<end; i++)
        res += numbers[i];
    
    cout << res;
    
    return 0;
}
