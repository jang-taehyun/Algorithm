/*
problem : 사탕이 n*n으로 채워졌을 때, 사탕의 색이 다른 인접한 두 칸을 골라 교환 한 후 모두 같은 색으로 이루어진 가장 긴 연속 부분을 골라 먹는 방법 중 먹을 수 있는 사탕의 최대 개수를 구해라
input : 보드의 크기 n, 보드에 채워져있는 사탕의 색상 color
output : 조건에 따라 먹을 수 있는 사탕의 최대 개수

idea : 행을 기준으로 바꾼 후 보드를 검사하고, 열을 기준으로 바꾼 후 보드를 검사한다.
*/
#include <iostream>
using namespace std;

// 보드의 크기 n
int n;
// 사탕이 들어가는 보드
char board[51][51];
// 조건에 따라 먹을 수 있는 사탕의 최대 개수 max
int res;

int Max(int x, int y) { return x > y ? x : y; }

void SwapCandy(char& x, char& y)
{
    char temp = x;
    x = y;
    y = temp;
}

void Check()
{
    // 먹은 사탕의 개수
    int count;
    // 전에 먹은 사탕의 색깔
    char color;

    // 열 기준으로 검사
    for (int column = 0; column < n; column++)
    {
        // 초기값 설정
        count = 1;
        color = board[column][0];

        // 열 기준으로 색깔이 같다면 +1을 하고, 다르면 count를 1로 되돌리고 전에 먹은 사탕의 color를 현재 탐색하고 있는 사탕의 색깔로 설정
        for (int row = 1; row < n; row++)
        {
            if (board[column][row] == color)
                count++;
            else
            {
                count = 1;
                color = board[column][row];
            }

            // res 업데이트
            res = Max(res, count);
        }
    }

    // 행 기준으로 검사
    for (int row = 0; row < n; row++)
    {
        // 초기값 설정
        count = 1;
        color = board[0][row];

        // 행 기준으로 색깔이 같다면 +1을 하고, 다르면 count를 1로 되돌리고 전에 먹은 사탕의 color를 현재 탐색하고 있는 사탕의 색깔로 설정
        for (int column = 1; column < n; column++)
        {
            if (board[column][row] == color)
                count++;
            else
            {
                count = 1;
                color = board[column][row];
            }

            // res 업데이트
            res = Max(res, count);
        }
    }
}

int main()
{
    // 보드의 크기 n과 보드에 채워져 있는 사탕의 색상 입력
    cin >> n;
    for (int column = 0; column < n; column++)
        for (int row = 0; row < n; row++)
            cin >> board[column][row];

    // 열을 기준으로 사탕의 위치를 바꾼 후 보드를 검사
    for (int column = 0; column < n; column++)
    {
        for (int row = 0; row < n - 1; row++)
        {
            SwapCandy(board[column][row], board[column][row + 1]);
            Check();
            SwapCandy(board[column][row], board[column][row + 1]);
        }
    }

    // 행을 기준으로 사탕의 위치를 바꾼 후 보드 검사
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < n - 1; column++)
        {
            SwapCandy(board[column][row], board[column + 1][row]);
            Check();
            SwapCandy(board[column][row], board[column + 1][row]);
        }
    }

    // 결과값 출력
    cout << res;

    return 0;
}