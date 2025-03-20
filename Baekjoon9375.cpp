#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int test;
    int clothesSize;
    map<string, int> clothTypeMap;
    map<string, int>::iterator iter;
    string clothType, cloth;
    int res = 1;
    
    cin >> test;
    while(test--)
    {
        cin >> clothesSize;
        for(int i=0; i<clothesSize; ++i)
        {
            cin >> cloth >> clothType;
            
            iter = clothTypeMap.find(clothType);
            if(iter == clothTypeMap.end())
                clothTypeMap.insert(make_pair(clothType, 2));
            else
                iter->second++;
        }
        
        for(iter = clothTypeMap.begin(); iter != clothTypeMap.end(); ++iter)
            res *= iter->second;
        --res;
        
        cout << res << '\n';
        
        res = 1;
        clothTypeMap.clear();
    }
    
    return 0;
}
