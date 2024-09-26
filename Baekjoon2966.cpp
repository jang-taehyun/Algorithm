#include <iostream>
#include <string>
using namespace std;

int len;
string input;
char Adrian[3] = {'A', 'B', 'C'};
char Bruno[4] = {'B', 'A', 'B', 'C'};
char Goran[6] = {'C', 'C', 'A', 'A', 'B', 'B'};
int res[3];
int Max=0;

int main()
{    
    cin >> len >> input;
    
    for(int i=0; i<len; i++)
    {
        if(input[i] == Adrian[i%3])
        {
            res[0]++;
            if(res[0] > Max)
                Max = res[0];
        }
        
        if(input[i] == Bruno[i%4])
        {
            res[1]++;
            if(res[1] > Max)
                Max = res[1];
        }
        
        if(input[i] == Goran[i%6])
        {
            res[2]++;
            if(res[2] > Max)
                Max = res[2];
        }
    }
    
    cout << Max << '\n';
    if(Max == res[0])
        cout << "Adrian" << '\n';
    if(Max == res[1])
        cout << "Bruno" << '\n';
    if(Max == res[2])
        cout << "Goran" << '\n';
    
    return 0;
}
