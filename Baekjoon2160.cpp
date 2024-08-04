#include <iostream>
#include <string>
#define MAX 99999999
using namespace std;

char board[5][7][50];
int diff[50][50];        // i번째 board와 j번째 board의 서로 다른 칸의 개수
int n;

int main()
{
    string tmp;
    int res1, res2, res3=MAX;
    
    cin >> n;
    for(int idx=0; idx<n; idx++)
    {
        for(int i=0; i<5; i++)
        {
            cin >> tmp;
            for(int j=0; j<7; j++)
                board[i][j][idx] = tmp[j];
        }
    }
    
    for(int i=0; i<5; i++)
        for(int j=0; j<7; j++)
            for(int idx=0; idx<n-1; idx++)
                for(int cmp=idx+1; cmp<n; cmp++)
                    if(board[i][j][idx] != board[i][j][cmp])
                        diff[idx][cmp]++;
    
    for(int idx=0; idx<n-1; idx++)
        for(int cmp=idx+1; cmp<n; cmp++)
            if(diff[idx][cmp] < res3)
            {
                res1 = idx;
                res2 = cmp;
                res3 = diff[idx][cmp];
            }
    
    cout << res1+1 << ' ' << res2+1;
    
    return 0;
}
