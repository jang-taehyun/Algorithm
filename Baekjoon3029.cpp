#include <iostream>
#include <string>
using namespace std;

int main()
{
    string current;
    string target;
    string tmp1, tmp2;
    int n1, n2, n3;
    bool tmp3 = false;
    string res;
    
    cin >> current >> target;
    
    for(int i=target.length()-1; i>=1; i-=3)
    {
        tmp1 = target[i-1];
        tmp1 += target[i];
        tmp2 = current[i-1];
        tmp2 += current[i];
        
        n1 = stoi(tmp1);
        n2 = stoi(tmp2);
        
        if(tmp3)
        {
            tmp3 = false;
            n1--;
        }
        
        if(n1 < n2)
        {
            if(!(i-1))
                n1 += 24;
            else
                n1 += 60;
            tmp3 = true;
        }
        
        n3 = n1 - n2;
        
        if(n3 < 10)
            res = "0" + to_string(n3) + res;
        else
            res = to_string(n3) + res;
        res = ":" + res;
    }
    
    res.erase(res.begin());
    
    tmp3 = true;
    for(int i=0; i<res.length(); i++)
    {
        if(res[i] != '0' && res[i] != ':')
        {
            tmp3 = false;
            break;
        }
    }
    
    if(tmp3)
    {
        res[0] = '2';
        res[1] = '4';
    }
    
    cout << res;
    
    return 0;
}
