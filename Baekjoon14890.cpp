#include <iostream>
using namespace std;

int bound, len;
int board[100][100] = {0, };
int res = 0;

void Solve()
{
    bool IsRoad = true, IsDown = false;;
    int startIdx=0;
    
    for(int i=0; i<bound; ++i)
    {
        IsRoad = true;
        startIdx=0;
        IsDown = false;
        
        for(int j=1; j<bound; ++j)
        {
            // 높이 차이가 2 이상인 경우
            if(abs(board[i][j] - board[i][j-1]) > 1)
            {
                IsRoad = false;
                break;
            }
            
            // 현재 높이가 더 높은 경우
            if(board[i][j] > board[i][j-1])
            {
                // 경사로 길이 충족 못하는 경우
                if(j - startIdx < len)
                {
                    IsRoad = false;
                    break;
                }
                
                startIdx=j;
            }
            // 현재 높이가 더 낮은 경우
            else if(board[i][j] < board[i][j-1])
            {
                // 내려가는 경사로 설치
                if(!IsDown)
                {
                    IsDown = true;
                }
                // 내려가는 경사로를 설치하는 도중 경사로 길이 충족 못하는 경우
                else if(IsDown && j - startIdx < len)
                {
                    IsRoad = false;
                    break;
                }
                
                startIdx=j;
            }
            
            // 내려가는 경사로를 설치하는 도중 길이를 충족하는 경우
            if(IsDown && j - startIdx + 1 >= len)
            {
                IsDown = false;
                startIdx = j+1;
            }
        }
        
        // 내려가는 경사로를 설치하는 도중 경사로 길이 충족 못하는 경우
        if(IsDown && bound - startIdx < len)
            IsRoad = false;
        
        if(IsRoad)
            res++;
    }
    
    for(int i=0; i<bound; ++i)
    {
        IsRoad = true;
        startIdx=0;
        IsDown = false;
        
        for(int j=1; j<bound; ++j)
        {
            // 높이 차이가 2 이상인 경우
            if(abs(board[j][i] - board[j-1][i]) > 1)
            {
                IsRoad = false;
                break;
            }
            
            // 현재 높이가 더 높은 경우
            if(board[j][i] > board[j-1][i])
            {
                // 경사로 길이 충족 못하는 경우
                if(j - startIdx < len)
                {
                    IsRoad = false;
                    break;
                }
                
                startIdx=j;
            }
            // 현재 높이가 더 낮은 경우
            else if(board[j][i] < board[j-1][i])
            {
                // 내려가는 경사로 설치
                if(!IsDown)
                {
                    IsDown = true;
                }
                // 내려가는 경사로를 설치하는 도중 경사로 길이 충족 못하는 경우
                else if(IsDown && j - startIdx < len)
                {
                    IsRoad = false;
                    break;
                }
                
                startIdx=j;
            }
            
            // 내려가는 경사로를 설치하는 도중 길이를 충족하는 경우
            if(IsDown && j - startIdx + 1 >= len)
            {
                IsDown = false;
                startIdx = j+1;
            }
        }
        
        // 내려가는 경사로를 설치하는 도중 경사로 길이 충족 못하는 경우
        if(IsDown && bound - startIdx < len)
            IsRoad = false;
        
        if(IsRoad)
            res++;
    }
}

int main()
{
    cin >> bound >> len;
    for(int i=0; i<bound; i++)
        for(int j=0; j<bound; j++)
            cin >> board[i][j];
    
    Solve();
    
    cout << res;
    
    return 0;
}
