#include <iostream>
#include <utility>
using namespace std;

int resourceCnt;
pair<int, char> origin[5][5];
pair<int, char> resource[10][4][4];

bool isChoose[10] = {false, };

int res = 0;

void DFS(int cnt);
void CheckBoard();
void SetBoard(int idx, int cnt);

int main()
{
    int value[4][4] = {0, };
    char color[4][4] = {0, };
    
    cin >> resourceCnt;
    for(int k=0; k<resourceCnt; ++k)
    {
        for(int i=0; i<4; ++i)
            for(int j=0; j<4; ++j)
                cin >> value[i][j];
        
        for(int i=0; i<4; ++i)
            for(int j=0; j<4; ++j)
                cin >> color[i][j];
        
        for(int i=0; i<4; ++i)
            for(int j=0; j<4; ++j)
                resource[k][i][j] = make_pair(value[i][j], color[i][j]);
    }
    
    DFS(0);
    
    cout << res;
    
    return 0;
}

void SetBoard(int idx, int cnt)
{
    pair<int, char> prev[5][5];
    pair<int, char> cur_resource[4][4];
    pair<int, char> copy[4][4];
    
    // origin 백업
    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
            prev[i][j] = origin[i][j];
    
    // 재료 세팅
    for(int i=0; i<4; ++i)
        for(int j=0; j<4; ++j)
            cur_resource[i][j] = resource[idx][i][j];
    
    // 재료를 origin에 적용
    for(int l=0; l<2; ++l)
    {
        for(int p=0; p<2; ++p)
        {
            // 현재 칸에서 90도씩 돌려보면서 재료를 적용
            for(int k=0; k<4; ++k)
            {
                // 재료를 적용
                for(int i=0; i<4; ++i)
                {
                    for(int j=0; j<4; ++j)
                    {
                        origin[l+i][p+j].first += cur_resource[i][j].first;
                        
                        if(origin[l+i][p+j].first < 0)
                            origin[l+i][p+j].first = 0;
                        if(origin[l+i][p+j].first > 9)
                            origin[l+i][p+j].first = 9;
                        
                        if('R' == cur_resource[i][j].second || 'B' == cur_resource[i][j].second
                           || 'G' == cur_resource[i][j].second || 'Y' == cur_resource[i][j].second)
                            origin[l+i][p+j].second = cur_resource[i][j].second;
                    }
                }
                
                // 탐색
                DFS(cnt+1);
                
                // origin 원상 복구
                for(int i=0; i<5; ++i)
                    for(int j=0; j<5; ++j)
                        origin[i][j] = prev[i][j];
                
                // 재료를 90도 돌리기
                for(int i=0; i<4; ++i)
                    for(int j=0; j<4; ++j)
                        copy[i][j] = cur_resource[i][j];
                
                for(int i=0; i<4; ++i)
                    for(int j=0; j<4; ++j)
                        cur_resource[i][j] = copy[3-j][i];
            }  
        }
    }
}

void CheckBoard()
{
    int r=0, b=0, g=0, y=0;
    int tmp = 0;
    
    for(int i=0; i<5; ++i)
    {
        for(int j=0; j<5; ++j)
        {
            if('R' == origin[i][j].second)
                r += origin[i][j].first;
            else if('B' == origin[i][j].second)
                b += origin[i][j].first;
            else if('G' == origin[i][j].second)
                g += origin[i][j].first;
            else if('Y' == origin[i][j].second)
                y += origin[i][j].first;
        }
    }
    
    tmp = (r * 7) + (b * 5) + (g * 3) + (y * 2);
    
    if(tmp > res)
        res = tmp;
}

void DFS(int cnt)
{
    if(cnt >= 3)
    {
        CheckBoard();
        return;
    }
    
    for(int i=0; i<resourceCnt; ++i)
    {
        if(!isChoose[i])
        {
            isChoose[i] = true;
            SetBoard(i, cnt);
            isChoose[i] = false;
        }
    }
}

