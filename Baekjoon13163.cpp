#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> v;
    string input;
    string tmp;
    int cnt;
    
    cin >> cnt;
    cin.ignore();
    
    while(cnt--)
    {
        getline(cin, input);
        
        for(int i=0; i<input.length(); ++i)
        {
            if(input[i] == ' ')
            {
                v.push_back(tmp);
                tmp = "";
            }
            else
                tmp += input[i];
        }
        
        v.push_back(tmp);
        tmp = "";
        
        cout << "god";
        for(int i=1; i<v.size(); ++i)
            cout << v[i];
        cout << '\n';
        
        v.clear();
    }
    
    return 0;
}
