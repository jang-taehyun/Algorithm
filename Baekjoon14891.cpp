#include <iostream>
#include <cstring>
using namespace std;

bool bCogwheelState[4][8] = { false, };
int nDirection[4] = { 0, };
bool bVisited[4] = {false, };

void SetCogwheelRotateState(int cur, int dir)
{
    int nextDir = (dir == 1 ? -1 : 1);
    
    if(bVisited[cur])
        return;
    
    bVisited[cur] = true;
    
    // 현재 바퀴의 돌리는 방향 저장
    nDirection[cur] = dir;
    
    // 왼쪽 바퀴 검사
    if(cur > 0)
    {
        if(bCogwheelState[cur][6] != bCogwheelState[cur-1][2])
            SetCogwheelRotateState(cur-1, nextDir);
    }
    
    // 오른쪽 바퀴 검사
    if(cur < 3)
    {
        if(bCogwheelState[cur][2] != bCogwheelState[cur+1][6])
            SetCogwheelRotateState(cur+1, nextDir);
    }
}

void RotateCogwheel(int cur)
{
    bool lastPolarity;
    
    if(!nDirection[cur])
        return;
    
    // 반시계 방향으로 회전
    if(nDirection[cur] == -1)
    {
        lastPolarity = bCogwheelState[cur][0];
        for(int i=0; i<7; ++i)
            bCogwheelState[cur][i] = bCogwheelState[cur][i+1];
        bCogwheelState[cur][7] = lastPolarity;
    }
    // 반시계 방향으로 회전
    else
    {
        lastPolarity = bCogwheelState[cur][7];
        for(int i=7; i>0; --i)
            bCogwheelState[cur][i] = bCogwheelState[cur][i-1];
        bCogwheelState[cur][0] = lastPolarity;
    }
}

int main()
{
    int test;
    int wheelNum, direction;
    char tmp;
    int res = 0, adder = 1;
    
    for(int i=0; i<4; ++i)
        for(int j=0; j<8; ++j)
        {
            cin >> tmp;
            bCogwheelState[i][j] = (tmp == '1' ? true : false);
        }
    
    cin >> test;
    while(test--)
    {
        cin >> wheelNum >> direction;
        
        SetCogwheelRotateState(wheelNum-1, direction);
        
        for(int i=0; i<4; ++i)
            RotateCogwheel(i);
        
        memset(nDirection, 0, sizeof(nDirection));
        memset(bVisited, false, sizeof(bVisited));
    }
    
    for(int i=0; i<4; ++i)
    {
        if(bCogwheelState[i][0])
            res += adder;
        
        adder *= 2;
    }
    
    cout << res;
    
    return 0;
}
