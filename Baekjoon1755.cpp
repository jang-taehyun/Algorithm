#include <iostream>
#include <string>
#include <map>
using namespace std;

string ConvertString(int n)
{
    string ret;
    string num = to_string(n);
    
    for(int i=0; i<num.length(); ++i)
    {
        switch(num[i])
        {
            case '0':
                ret += "zero ";
                break;
            case '1':
                ret += "one ";
                break;
            case '2':
                ret += "two ";
                break;
            case '3':
                ret += "three ";
                break;
            case '4':
                ret += "four ";
                break;
            case '5':
                ret += "five ";
                break;
            case '6':
                ret += "six ";
                break;
            case '7':
                ret += "seven ";
                break;
            case '8':
                ret += "eight ";
                break;
            default:
                ret += "nine ";
                break;
        }
    }
    
    return ret;
}

int main()
{
    int start, end;
    string str;
    map<string, int> m;
    map<string, int>::iterator iter;
    int cnt=0;
    
    cin >> start >> end;
    
    for(int i=start; i<=end; ++i)
    {
        str = ConvertString(i);
        m.insert(make_pair(str, i));
    }
    
    for(iter = m.begin(); iter != m.end(); ++iter)
    {
        cout << iter->second << ' ';
        
        ++cnt;
        if(!(cnt % 10))
            cout << '\n';
    }
    
    return 0;
}
