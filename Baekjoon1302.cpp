#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int cnt;
    string input;
    map<string, int> seller;
    map<string, int>::iterator iter;
    string res;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> input;
        
        iter = seller.find(input);
        if(seller.end() == iter)
            seller.insert(make_pair(input, 1));
        else
            iter->second++;
    }
    
    cnt = 0;
    for(iter = seller.begin(); iter != seller.end(); ++iter)
        if(iter->second > cnt)
        {
            res = iter->first;
            cnt = iter->second;
        }
    
    cout << res;
    
    return 0;
}
