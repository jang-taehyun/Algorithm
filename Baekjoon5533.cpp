#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int len;
    int input[200][3];
    int res[200];
    int Overlap[101];
    
    memset(res, 0, sizeof(res));
    
    cin >> len;
    
    for(int i=0; i<len; i++)
        for(int j=0; j<3; j++)
            cin >> input[i][j];
    
    for(int i=0; i<3; i++)
    {
        memset(Overlap, 0, sizeof(Overlap));
        
        for(int j=0; j<len; j++)
            Overlap[input[j][i]]++;
        
        for(int j=0; j<len; j++)
            if(Overlap[input[j][i]] == 1)
                res[j] += input[j][i];
    }
    
    for(int i=0; i<len; i++)
        cout << res[i] << '\n';
    
    return 0;
}
