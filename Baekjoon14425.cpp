#include <iostream>
#include <set>
using namespace std;

int main()
{
    int stringGroupSize;
    set<string> stringGroup;
    int compareSize;
    string input;
    int res = 0;
    
    cin >> stringGroupSize >> compareSize;
    while(stringGroupSize--)
    {
        cin >> input;
        stringGroup.insert(input);
    }
    
    while(compareSize--)
    {
        cin >> input;
        
        if(stringGroup.end() != stringGroup.find(input))
            res++;
    }
    
    cout << res;
    
    return 0;
}
