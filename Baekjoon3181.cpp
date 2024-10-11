#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string input;
    string res="";
    string tmp;
    int idx;
    vector<string> arr;
    bool IsSame = false;
    
    arr.push_back("i");
    arr.push_back("pa");
    arr.push_back("te");
    arr.push_back("ni");
    arr.push_back("niti");
    arr.push_back("a");
    arr.push_back("ali");
    arr.push_back("nego");
    arr.push_back("no");
    arr.push_back("ili");
    
    getline(cin, input);
    
    for(int i=0; i<input.length(); i++)
    {
        tmp = "";
        idx = i;
        IsSame = false;
        
        while(input[idx] != ' ' && input[idx] != 0)
        {
            tmp += input[idx];
            idx++;
        }
        
        if(i == 0)
            res += (tmp[0] - ('a' - 'A'));
        else
        {
            for(int i=0; i<arr.size(); i++)
                if(arr[i] == tmp)
                {
                    IsSame = true;
                    break;
                }
            
            if(!IsSame)
                res += (tmp[0] - ('a' - 'A'));
        }
        
        i = idx;
    }
    
    cout << res;
    
    return 0;
}
