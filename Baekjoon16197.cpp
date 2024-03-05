/*
problem : board 위에 2개의 동전과 4가지 버튼이 있을 때, 동전 하나만 떨어뜨리기 위해 버튼을 눌어야 하는 최소 횟수를 구해라.
input : board의 빈 칸과 벽의 정보, 동전 2개의 위치
output : 동전 1개를 떨어뜨리기 위해 눌러야하는 버튼의 최소 횟수

idea
- DFS 방식을 이용해 버튼을 누르고, 버튼을 누른 후에 몇 개의 동전이 board에 빠져 나갔는지 확인한다.
  0 : 계속 진행
  1 : 결과값을 update
  2 : 탐색 중단
- 만약 결과값이 10회 이상인 경우, -1을 출력한다.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#define BOUND 10
using namespace std;

char board[20][20];                        // board의 정보
                                           // . : 빈 칸 / # : 벽
int Column, Row;                           // board의 column, Row
int dx[4] = { 0, 0, -1, 1 };                 // 누를 수 있는 4가지 버튼
int dy[4] = { 1, -1, 0, 0 };
int Result = 99999999;                       // 버튼을 누르는 최소 횟수

bool IsRange(int px, int py) { return (0 <= px && px < Column && 0 <= py && py < Row); }

void DFS(int cx1, int cy1, int cx2, int cy2, int direction, int ButtonCount)
{
    // 만약 버튼을 이전에 찾았던 횟수보다 더 많이 누르면 더 이상 탐색하지 않는다.
    if (ButtonCount > Result)
        return;

    // 만약 10회 이상 누르면 결과값만 update한다.
    if (ButtonCount > BOUND)
    {
        Result = min(Result, ButtonCount);
        return;
    }

    int nx1 = cx1 + dx[direction];
    int ny1 = cy1 + dy[direction];
    int nx2 = cx2 + dx[direction];
    int ny2 = cy2 + dy[direction];

    // 현재 동전이 몇 개 떨어졌는지 확인
    // 2개 모두 떨어진 경우
    if (!IsRange(nx1, ny1) && !IsRange(nx2, ny2))
        return;
    // 1개만 떨어진 경우
    else if ((IsRange(nx1, ny1) && !IsRange(nx2, ny2)) || (!IsRange(nx1, ny1) && IsRange(nx2, ny2)))
    {
        Result = min(Result, ButtonCount);
        return;
    }

    // 이동한 위치가 벽이라면 원상 복구한다.
    if (board[nx1][ny1] == '#')
    {
        nx1 = cx1;
        ny1 = cy1;
    }
    if (board[nx2][ny2] == '#')
    {
        nx2 = cx2;
        ny2 = cy2;
    }

    // DFS을 이용해 버튼을 더 누른다.
    for (int i = 0; i < 4; i++)
    {
        DFS(nx1, ny1, nx2, ny2, i, ButtonCount + 1);
    }
}

int main()
{
    string input;
    int CoinPosX[2];
    int CoinPosY[2];

    // board의 Column과 Row 정보를 입력받고, board의 상태와 동전 2개의 위치를 입력받는다.
    int index = 0;
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;

        for (int j = 0; j < Row; j++)
        {
            board[i][j] = input[j];

            if (board[i][j] == 'o')
            {
                CoinPosX[index] = i;
                CoinPosY[index] = j;
                index++;
            }
        }
    }

    // DFS 탐색을 통해 버튼을 누르는 횟수를 구한다.
    for (int i = 0; i < 4; i++)
    {
        DFS(CoinPosX[0], CoinPosY[0], CoinPosX[1], CoinPosY[1], i, 1);
    }

    // 결과값 출력
    if (Result > BOUND)
        Result = -1;
    cout << Result;

    return 0;
}