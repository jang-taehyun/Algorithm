#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    vector<int> storage;
    int len;
    int tmp;
    
    while(1)
    {
        cin >> len;
        if(!len)
            break;
        
        for(int i=0; i<len; i++)
        {
            cin >> tmp;
            storage.push_back(tmp);
        }
        
        tmp = storage[0];
        cout << tmp << ' ';
        for(int i=1; i<storage.size(); i++)
        {
            if(tmp != storage[i])
                cout << storage[i] << ' ';
            tmp = storage[i];
        }
        cout << "$\n";
        
        storage.clear();
    }
    
    return 0;
}
