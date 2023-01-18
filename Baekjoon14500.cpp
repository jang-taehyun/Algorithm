/*
problem : n*m 칸에서 테트로미노가 놓인 칸의 합이 최대가 되는 경우의 값을 구해라.
input : column n, row m, n*m 칸에 적힌 숫자
output : 테트로미노가 놓은 킨이 합이 최대가 되는 경우의 값

idea : 어느 시점에서 DFS 방식을 이용해 depth가 4인 경우 탐색을 종료하고 현재 찾은 값 중 가장 큰 값인지 확인한다.
ㅗ, ㅏ, ㅜ, ㅓ 모양은 따로 계산한 후 5가지의 방식으로 탐색한 값 중 가장 큰 값을 찾는다.
*/
#define MAX_SIZE 500
#define END_DEPTH 4
#include <iostream>
#include <cstring>
using namespace std;

int board[MAX_SIZE][MAX_SIZE];
bool isVisited[MAX_SIZE][MAX_SIZE];
int MoveColumn[4] = { 0, 0, 1, -1 };
int MoveRow[4] = { 1, -1, 0, 0 };

int Max(int x, int y) { return x > y ? x : y; }

void DFS(int column, int row, int depth, int sum, int* result, const int boundColumn, const int boundRow)
{
    // 현재 위치 방문
    isVisited[column][row] = true;

    // depth가 4이면 저장된 값과 계산된 값 비교
    if (depth >= END_DEPTH)
    {
        *result = Max(*result, sum);
        return;
    }

    // 다음 위치 탐색
    for (int i = 0; i < 4; i++)
    {
        // 다음 위치 지정
        int NextPointColumn = column + MoveColumn[i];
        int NextPointRow = row + MoveRow[i];

        // 다음 위치에 대한 예외 처리
        if (NextPointColumn >= boundColumn || NextPointRow >= boundRow || NextPointColumn < 0 || NextPointRow < 0)
            continue;
        if (isVisited[NextPointColumn][NextPointRow])
            continue;

        // 다음 위치 방문
        DFS(NextPointColumn, NextPointRow, depth + 1, sum + board[NextPointColumn][NextPointRow], result, boundColumn, boundRow);

        // 방문 후 다시 원상복구
        isVisited[NextPointColumn][NextPointRow] = false;
    }
}

// ㅗ 모양
void Shape1(int column, int row, int* result)
{
    int res = board[column][row] + board[column][row + 1] + board[column][row + 2] + board[column - 1][row + 1];
    *result = Max(*result, res);
}

// ㅜ 모양
void Shape2(int column, int row, int* result)
{
    int res = board[column][row] + board[column][row + 1] + board[column][row + 2] + board[column + 1][row + 1];
    *result = Max(*result, res);
}

// ㅏ 모양
void Shape3(int column, int row, int* result)
{
    int res = board[column][row] + board[column + 1][row] + board[column + 2][row] + board[column + 1][row + 1];
    *result = Max(*result, res);
}

// ㅓ 모양
void Shape4(int column, int row, int* result)
{
    int res = board[column][row] + board[column - 1][row + 1] + board[column][row + 1] + board[column + 1][row + 1];
    *result = Max(*result, res);
}

int main()
{
    // column n, row m
    int n = 0, m = 0;
    // 최대값 max
    int max = 0;

    // column, row, board 입력
    cin >> n >> m;
    for (int column = 0; column < n; column++)
        for (int row = 0; row < m; row++)
            cin >> board[column][row];

    // 5가지 경우에 대해 모든 위치를 탐색하면서 최대값 찾기
    for (int column = 0; column < n; column++)
    {
        for (int row = 0; row < m; row++)
        {
            // 방문 여부 초기화
            memset(isVisited, false, sizeof(isVisited));

            // 5가지 경우를 모두 탐색
            DFS(column, row, 1, board[column][row], &max, n, m);
            if (column - 1 >= 0 && row + 2 < m)
                Shape1(column, row, &max);
            if (column + 1 < n && row + 2 < m)
                Shape2(column, row, &max);
            if (column + 2 < n && row + 1 < m)
                Shape3(column, row, &max);
            if (column + 1 < n && column - 1 >= 0 && row + 1 < m)
                Shape4(column, row, &max);
        }
    }

    // 결과값 출력
    cout << max;

    return 0;
}