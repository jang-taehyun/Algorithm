/*
Problem : n*n 체스판에 n개의 퀸이 서로 공격할 수 없게 배치하는 방법의 수를 구해라.
input : n
output : n개의 퀸이 서로 공격할 수 없게 배치하는 방법의 수

idea
- n*n 체스판에 n개의 퀸을 놓는 방법을 row가 level, node가 (column, row)인 state space tree로 생각한다.
- 같은 row열에 퀸이 1개만 놓을 수 있는 방법으로 시작하여 DFS 방식으로 탐색한다.
- 퀀을 체스판에 놓기 전에, 현재 체스판에 세로, 대각선 열을 확인해 서로 공격할 수 있는지 없는지 판단한다.
- 만약 서로 공격할 수 있다면, 탐색을 중단한다.
*/
#include <iostream>
#include <cmath>
using namespace std;

int BoardLength;                 // 체스판의 한 변의 길이
int Result = 0;                    // n*n 체스판에 n개의 퀸이 서로 공격할 수 없게 배치하는 방법의 수
int QueenRowPosition[15];        // 현재 queen들이 놓아진 위치
                                 // index : column, value : row

// 현재 체스판에 가로, 대각선 열에 queen이 2개 이상 놓여져 있는지 확인
bool IsPromising(int CurrentColumn)
{
    for (int i = 0; i < CurrentColumn; i++)
    {
        // 같은 가로 열에 있거나, 같은 대각선에 있다면 false 반환
        if ((QueenRowPosition[i] == QueenRowPosition[CurrentColumn]) || (abs(QueenRowPosition[i] - QueenRowPosition[CurrentColumn]) == CurrentColumn - i))
            return false;
    }

    return true;
}

// 한 개의 column열마다 queen을 1개씩 놓으면서 state space tree를 DFS 방식으로 탐색
void DFS(int CurrentColumn)
{
    // 현재 board의 상태가 promising 인지 확인
    if (IsPromising(CurrentColumn))
    {
        // 만약 n개의 queen을 모두 놓았다면, 결과값을 1 증가
        if (CurrentColumn >= BoardLength - 1)
        {
            Result++;
            return;
        }

        // 다음 column에 queen을 1개씩 놓는다.
        for (int i = 0; i < BoardLength; i++)
        {
            QueenRowPosition[CurrentColumn + 1] = i;
            DFS(CurrentColumn + 1);
        }
    }
}

int main()
{
    // 체스판 한 변의 길이를 입력
    cin >> BoardLength;

    // state space tree를 DFS 방식으로 탐색
    // 한 개의 column열마다 queen을 1개씩 놓는다.
    for (int i = 0; i < BoardLength; i++)
    {
        QueenRowPosition[0] = i;
        DFS(0);
    }

    // 결과값 출력
    cout << Result;

    return 0;
}