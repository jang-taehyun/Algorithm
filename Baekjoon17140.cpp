#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int board[100][100] = {0, };
int r, c, t;
int columLen = 3;
int rowLen = 3;
int res = 0;

bool Comp(pair<int, int> idx1, pair<int, int> idx2)
{
    if(idx1.second == idx2.second)
        return (idx1.first < idx2.first);
    else
        return (idx1.second < idx2.second);
}

void SortRow()
{
    vector<pair<int, int>> storage;    // first : 숫자, second 등장 횟수
    int Exist[101] = {0, };
    int idx = 0;
    int tmp = 0;
    
    for(int i=0; i<rowLen; ++i)
    {
        // 현재 행에서 각 숫자들이 몇 번 나왔는지 확인
        for(int j=0; j<columLen; ++j)
            ++Exist[board[i][j]];
        
        // 현재 행 초기화
        for(int j=0; j<100; ++j)
            board[i][j] = 0;
        
        // 숫자(first), 등장 횟수(second)을 묶어서 vector에 넣기
        for(int j=1; j<101; ++j)
            if(Exist[j])
                storage.push_back(make_pair(j, Exist[j]));
        
        // 정렬
        sort(storage.begin(), storage.end(), Comp);
        
        // vector의 크기만큼 board에 넣기
        for(int j=0; j<storage.size(); ++j)
        {
            if(idx < 100)
                board[i][idx++] = storage[j].first;
            if(idx < 100)
                board[i][idx++] = storage[j].second;
        }
        
        // column 길이 임시 저장
        tmp = (tmp < idx ? idx : tmp);
        
        // vector, idx, Exist 초기화
        memset(Exist, 0, sizeof(Exist));
        storage.clear();
        idx = 0;
    }
    
    // column 길이 업데이트
    columLen = tmp;
}

void SortColumn()
{
    vector<pair<int, int>> storage;    // first : 숫자, second 등장 횟수
    int Exist[101] = {0, };
    int idx = 0;
    int tmp = 0;
    
    for(int i=0; i<columLen; ++i)
    {
        // 현재 열에서 각 숫자들이 몇 번 나왔는지 확인
        for(int j=0; j<rowLen; ++j)
            ++Exist[board[j][i]];
        
        // 현재 열 초기화
        for(int j=0; j<100; ++j)
            board[j][i] = 0;
        
        // 숫자(first), 등장 횟수(second)을 묶어서 vector에 넣기
        for(int j=1; j<101; ++j)
            if(Exist[j])
                storage.push_back(make_pair(j, Exist[j]));
        
        // 정렬
        sort(storage.begin(), storage.end(), Comp);
        
        // vector의 크기만큼 board에 넣기
        for(int j=0; j<storage.size(); ++j)
        {
            if(idx < 100)
                board[idx++][i] = storage[j].first;
            if(idx < 100)
                board[idx++][i] = storage[j].second;
        }
        
        // row 길이 임시 저장
        tmp = (tmp < idx ? idx : tmp);
        
        // vector, idx, Exist 초기화
        memset(Exist, 0, sizeof(Exist));
        storage.clear();
        idx = 0;
    }
    
    // row의 길이 업데이트
    rowLen = tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    bool IsFind = false;
    
    cin >> r >> c >> t;
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            cin >> board[i][j];
    
    --r;
    --c;
    
    while(1)
    {
        if(t == board[r][c])
        {
            IsFind = true;
            break;
        }
        
        if(res > 100)
            break;
        
        if(rowLen >= columLen)
            SortRow();
        else
            SortColumn();
        
        res++;
    }
    
    cout << (IsFind ? res : -1);
    
    return 0;
}
