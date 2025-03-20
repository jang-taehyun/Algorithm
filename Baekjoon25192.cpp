#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    int count;
    set<string> chat;
    string input;
    int res = 0;
    
    cin >> count;
    while(count--)
    {
        cin >> input;
        
        if("ENTER" == input)
        {
            res += chat.size();
            chat.clear();
        }
        else
        {
            if(chat.end() == chat.find(input))
                chat.insert(input);
        }
    }
    
    if(!chat.empty())
        res += chat.size();
    
    cout << res;
    
    return 0;
}
