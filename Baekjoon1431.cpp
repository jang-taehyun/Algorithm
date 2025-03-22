#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool comp(string& r1, string& r2)
{
    int tmp1=0, tmp2=0;
    
    if(r1.length() != r2.length())
        return (r1.length() < r2.length());
    
    for(int i=0; i<r1.length(); ++i)
    {
        if('0' <= r1[i] && r1[i] <= '9')
            tmp1 += (r1[i] - '0');
        if('0' <= r2[i] && r2[i] <= '9')
            tmp2 += (r2[i] - '0');
    }
    
    if(tmp1 != tmp2)
        return (tmp1 < tmp2);
    
    for(int i=0; i<r1.length(); ++i)
    {
        if(r1[i] != r2[i])
        {
            if(('0' <= r1[i] && r1[i] <= '9') && ('0' <= r2[i] && r2[i] <= '9'))
                return (r1[i] < r2[i]);
            if(('A' <= r1[i] && r1[i] <= 'Z') && ('A' <= r2[i] && r2[i] <= 'Z'))
                return (r1[i] < r2[i]);
            
            if(('0' <= r1[i] && r1[i] <= '9') && ('A' <= r2[i] && r2[i] <= 'Z'))
                return true;
            if(('0' <= r2[i] && r2[i] <= '9') && ('A' <= r1[i] && r1[i] <= 'Z'))
                return false;
        }
    }
}

int main()
{
    int len;
    vector<string> input;
    string tmp;
    
    cin >> len;
    while(len--)
    {
        cin >> tmp;
        input.push_back(tmp);
    }
    
    sort(input.begin(), input.end(), comp);
    
    for(int i=0; i<input.size(); ++i)
        cout << input[i] << '\n';
    
    return 0;
}
