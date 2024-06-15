#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int input_count;
    vector<int> weight;
    int tmp1, tmp2;
    int res;
    
    cin >> input_count;
    for(int i=0; i<input_count; i++)
    {
        cin >> tmp1;
        weight.push_back(tmp1);
    }
    
    sort(weight.begin(), weight.begin()+input_count, greater<>());
    
    res = weight[0];
    while(!weight.empty())
    {
        if(res < weight.back() * weight.size())
            res = weight.back() * weight.size();
        
        weight.pop_back();
    }
        
    cout << res;
    
    return 0;
}
