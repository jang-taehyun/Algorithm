#include <iostream>
#define INF 987654321
using namespace std;

int column;
int board[100000][3];

int solution(bool IsFindMax)
{
    int res[3] = { 0, };
    int prev[3] = { 0, };
    int tmp = (IsFindMax ? 0 : INF);
    
    for(int i=0; i<3; ++i)
        res[i] = board[0][i];
    
    for(int i=1; i<column; ++i)
    {
        for(int j=0; j<3; ++j)
            prev[j] = res[j];
        
        // row idx : 0
        tmp = (IsFindMax ? 0 : INF);
        for(int j=0; j<2; ++j)
        {
            if(IsFindMax && prev[j] > tmp)
                tmp = prev[j];
            else if(!IsFindMax && prev[j] < tmp)
                tmp = prev[j];
        }
        res[0] = tmp + board[i][0];
        
        // row idx : 1
        tmp = (IsFindMax ? 0 : INF);
        for(int j=0; j<3; ++j)
        {
            if(IsFindMax && prev[j] > tmp)
                tmp = prev[j];
            else if(!IsFindMax && prev[j] < tmp)
                tmp = prev[j];
        }
        res[1] = tmp + board[i][1];
        
        // row idx : 2
        tmp = (IsFindMax ? 0 : INF);
        for(int j=1; j<3; ++j)
        {
            if(IsFindMax && prev[j] > tmp)
                tmp = prev[j];
            else if(!IsFindMax && prev[j] < tmp)
                tmp = prev[j];
        }
        res[2] = tmp + board[i][2];
    }
    
    tmp = (IsFindMax ? 0 : INF);
    for(int i=0; i<3; ++i)
    {
        if(IsFindMax && res[i] > tmp)
            tmp = res[i];
        else if(!IsFindMax && res[i] < tmp)
            tmp = res[i];
    }
    
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> column;
    for(int i=0; i<column; ++i)
        for(int j=0; j<3; ++j)
            cin >> board[i][j];
    
    cout << solution(true) << ' ' << solution(false);
    
    return 0;
}
