#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<string, string>> arr;
    string tmp1, tmp2;
    int len;
    
    while(1)
    {
        cin >> len;
        if(!len)
            break;
        
        for(int i=0; i<len; i++)
        {
            cin >> tmp1;
            tmp2 = tmp1;
            
            for(int j=0; j<tmp2.length(); j++)
                if(tmp2[j] >= 'a' && tmp2[j] <= 'z')
                    tmp2[j] -= 32;
            
            arr.push_back(make_pair(tmp2, tmp1));
        }
        
        sort(arr.begin(), arr.end());
        cout << arr[0].second << '\n';
        
        arr.clear();
    }
    
    return 0;
}
