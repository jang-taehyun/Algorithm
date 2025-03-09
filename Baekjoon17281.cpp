#include <iostream>
#include <queue>
using namespace std;

int cnt;
int score[50][9] = {0, };
bool IsChoose[9] = {false, };
int arr[9] = {0, };
int res = 0;

void DFS(int count)
{
    if(count >= 9)
    {
        queue<pair<int, int>> q;    // 선수 번호, 현재 루 위치
        bool IsInGround[9] = {false, };
        int idx = 0;
        int outcount = 0;
        int player = 0;
        int location = 0;
        int qsize = 0;
        int tmp = 0;
        
        for(int i=0; i<cnt; ++i)
        {
            while(outcount < 3)
            {
                if(IsInGround[arr[idx]])
                {
                    idx = (idx + 1) % 9;
                    continue;
                }
                
                if(score[i][arr[idx]])
                {
                    // 홈런
                    if(4 == score[i][arr[idx]])
                    {
                        tmp = tmp + q.size() + 1;
                        
                        while(!q.empty())
                        {
                            IsInGround[q.front().first] = false;
                            q.pop();
                        }
                    }
                    else
                    {
                        qsize = q.size();
                        while(qsize--)
                        {
                            player = q.front().first;
                            location = q.front().second;
                            q.pop();
                            
                            if(location + score[i][arr[idx]] >= 4)
                            {
                                IsInGround[player] = false;
                                tmp++;
                            }
                            else
                                q.push(make_pair(player, location + score[i][arr[idx]]));
                        }
                        
                        q.push(make_pair(arr[idx], score[i][arr[idx]]));
                        IsInGround[arr[idx]] = true;
                    }
                }   
                else
                    ++outcount;
                
                idx = (idx + 1) % 9;
            }
            
            while(!q.empty())
            {
                IsInGround[q.front().first] = false;
                q.pop();
            }  
            outcount = 0;
        }
        
        if(tmp > res)
            res = tmp;
        
        return;
    }
    
    if(count != 3)
    {
        for(int i=1; i<9; ++i)
        {
            if(!IsChoose[i])
            {
                IsChoose[i] = true;
                arr[count] = i;
                DFS(count+1);
                IsChoose[i] = false;
            }
        }
    }
    else
        DFS(count+1);
}

int main()
{
    arr[3] = 0;
    IsChoose[0] = true;
    
    cin >> cnt;
    for(int i=0; i<cnt; ++i)
        for(int j=0; j<9; ++j)
            cin >> score[i][j];
    
    DFS(0);
    
    cout << res;
    
    return 0;
}
