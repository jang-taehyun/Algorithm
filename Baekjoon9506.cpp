#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int input;
    vector<int> v;
    int sum = 0;
    bool IsExist[100001] = {false, };
    
    while(1)
    {
        cin >> input;
        
        if(-1 == input)
            break;
        
        for(int i=1; i<=input/2; ++i)
            if(!(input % i))
            {
                if(!IsExist[i])
                {
                    sum += i;
                    v.push_back(i);
                    IsExist[i] = true;
                }
                
                if((input/i) != input && !IsExist[input/i])
                {
                    sum += (input / i);
                    v.push_back(input / i);
                    IsExist[input/i] = true;
                }
            }
        
        sort(v.begin(), v.end());
        
        if(sum == input)
        {
            cout << input << " = ";
            for(int i=0; i<v.size()-1; ++i)
                cout << v[i] << " + ";
            cout << v[v.size()-1] << '\n';
        }
        else
            cout << input << " is NOT perfect." << '\n';
        
        sum = 0;
        v.clear();
        memset(IsExist, false, sizeof(IsExist));
    }
    
    return 0;
}
