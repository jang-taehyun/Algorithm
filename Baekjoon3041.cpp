#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char origin[4][4] = {
    {'A', 'B', 'C', 'D'},
    {'E', 'F', 'G', 'H'},
    {'I', 'J', 'K', 'L'},
    {'M', 'N', 'O', '.'}
                    };
    char input[4][4];
    bool IsFind = false;
    int res=0;
    
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            cin >> input[i][j];
    
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            if(input[i][j] != '.' && input[i][j] != origin[i][j])
            {
                IsFind = false;
                
                for(int idx1=0; idx1<4; idx1++)
                {
                    if(IsFind)
                        break;
                    
                    for(int idx2=0; idx2<4; idx2++)
                        if(input[i][j] == origin[idx1][idx2])
                        {
                            IsFind = true;
                            res += abs(i-idx1);
                            res += abs(j-idx2);
                            break;
                        }
                }
            }
        }
    
    cout << res;
    
    return 0;
}
