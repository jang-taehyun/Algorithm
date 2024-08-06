#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    char a;
    int res=0;
    
    while(1)
    {
        cin >> a;
        if('#' == a)
            break;
        cin.ignore();
        
        getline(cin, str);
    
        for(int i=0; i<str.length(); i++)
            if(a == str[i] || a-32 == str[i])
                res++;
    
        cout << a << ' ' << res << '\n';
        res=0;
    }
    
    
    return 0;
}
