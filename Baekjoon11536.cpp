#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int cnt;
    string input;
    vector<string> v;
    int increase=0, decrease=0;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> input;
        v.push_back(input);
    }
    
    for(int i=0; i<v.size()-1; ++i)
    {
        if(v[i] < v[i+1])
            ++increase;
        else
            ++decrease;
    }
    
    if(increase == v.size()-1)
        cout << "INCREASING";
    else if(decrease == v.size()-1)
        cout << "DECREASING";
    else
        cout << "NEITHER";
    
    return 0;
}
