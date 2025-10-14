#include <iostream>
#include <string>
using namespace std;

int LeftRemove(const string& str)
{
    int left=0, right=str.length()-1, ret=0;
    bool flag=false;
    
    while(left < right)
    {
        if(str[left] != str[right])
        {
            if(!flag && str[left + 1] == str[right])
            {
                flag = true;
                ++left;
                ret = 1;
            }
            else
            {
                ret = 2;
                break;
            }
        }
        
        ++left;
        --right;
    }
    
    return ret;
}

int RightRemove(const string& str)
{
    int left=0, right=str.length()-1, ret=0;
    bool flag=false;
    
    while(left < right)
    {
        if(str[left] != str[right])
        {
            if(!flag && str[left] == str[right - 1])
            {
                flag = true;
                --right;
                ret = 1;
            }
            else
            {
                ret = 2;
                break;
            }
        }
        
        ++left;
        --right;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cnt;
    string input;
    int ret1, ret2;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> input;
        
        ret1 = LeftRemove(input);
        ret2 = RightRemove(input);
        
        if(!ret1 || !ret2)
            cout << 0 << '\n';
        else
            cout << (ret1 < ret2 ? ret1 : ret2) << '\n';
    }
    
    return 0;
}
