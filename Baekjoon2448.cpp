#include <iostream>
#include <string>
#include <vector>
using namespace std;

int height;
vector<string> res;
string top = "  *   ";
string mid = " * *  ";
string bottom = "***** ";

void recur(int y, int x, int h)
{
    if(h <= 3)
    {
        for(int i=0; i<3; i++)
            while(res[y+i].length() < x-2)
                res[y+i] += " ";
        
        res[y] += top;
        res[y+1] += mid;
        res[y+2] += bottom;
        
        return;
    }
    
    recur(y, x, h/2);
    recur(y+h/2, x-h/2, h/2);
    recur(y+h/2, x+h/2, h/2);
}

int main()
{
    cin >> height;
    for(int i=0; i<height; i++)
        res.push_back("");
    
    recur(0, height-1, height);
    
    for(int i=height-2; i>=0; i--)
        while(res[height-1].length() > res[i].length())
            res[i] += " ";
    
    for(int i=0; i<height; i++)
        cout << res[i] << '\n';
    
    return 0;
}
