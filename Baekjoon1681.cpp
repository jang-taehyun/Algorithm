#include <iostream>
#include <string>
using namespace std;

int main()
{
    int res=0;
    int count;
    char notInclude;
    string tmp;
    bool flag = false;
    
    cin >> count;
    cin >> notInclude;
    
    for(int i=0; i<count; i++)
    {
        res++;
        flag = false;
        while(!flag)
        {
            flag = true;
            tmp = to_string(res);
            for(int j=0; j<tmp.length(); j++)
            {
                if(tmp[j] == notInclude)
                {
                    flag=false;
                    res++;
                    break;
                }
            }
        }
        
        if(i == count-1)
            cout << res;
    }
    
    return 0;
}
