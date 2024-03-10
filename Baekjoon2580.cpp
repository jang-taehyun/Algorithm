/*
Problem : 스도쿠 판에 있는 숫자들의 정보가 주어질 때, 모든 빈칸이 채워진 모습을 출력해라.
input : 스도쿠 판에 있는 숫자들의 정보
output : 스도쿠 판이 완성된 모습

idea
- 스도쿠 판 중 비어있는 위치(0으로 입력된 위치)를 따로 저장한다.
- 비어있는 위치에 1~9까지의 숫자를 집어넣고, 넣은 숫자가 가로, 세로열, 3*3 정사각형 내에 있는지 확인한다.(promising 조건)
- 만약 집어넣은 숫자가 가로, 세로열, 3*3 정사각형 내에 없다면, 비어있는 다른 위치에 1~9까지의 숫자를 집어넣고 promising 조건을 확인한다.
*/
#include <iostream>
#include <vector>
using namespace std;

int Board[9][9];                            // 입력된 스도쿠 판
vector<pair<int, int>> EmptyPosition;       // 비어있는 위치를 모아놓은 queue
                                            // first : column 좌표, second : row 좌표
int EmptyPositionCount;                     // 비어있는 위치의 개수

bool Promising(int CheckX, int CheckY)
{
    // 체크할 숫자
    int CheckNumber = Board[CheckX][CheckY];

    // column, row 확인
    for (int i = 0; i < 9; i++)
    {
        if (Board[CheckX][i] == CheckNumber && i != CheckY)
            return false;
        if (Board[i][CheckY] == CheckNumber && i != CheckX)
            return false;
    }

    // 3*3 정사각형 확인
    int StartX = (CheckX / 3) * 3;
    int StartY = (CheckY / 3) * 3;
    for (int i = StartX; i < StartX + 3; i++)
    {
        for (int j = StartY; j < StartY + 3; j++)
        {
            // 만약 집어넣은 칸이라면 다음 칸을 확인
            if (i == CheckX && j == CheckY)
                continue;

            if (Board[i][j] == CheckNumber)
                return false;
        }
    }

    return true;
}

void Bruteforce(int cnt)
{
    // 만약 비어있는 곳에 숫자를 모두 채워넣었다면, 완성된 스도쿠 판을 출력하고 프로그램 종료
    if (cnt >= EmptyPositionCount)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << Board[i][j] << ' ';
            cout << '\n';
        }

        exit(0);
    }

    // queue에서 비어있는 좌표를 하나 꺼내서 1~9까지 숫자 중 하나를 넣고, promising 조건을 확인한다.
    int CurX = EmptyPosition[cnt].first;
    int CurY = EmptyPosition[cnt].second;
    for (int i = 1; i < 10; i++)
    {
        Board[CurX][CurY] = i;
        if (Promising(CurX, CurY))
            Bruteforce(cnt + 1);
    }

    // 못 채웠을 경우 원상복구
    Board[CurX][CurY] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 스도쿠 정보 입력
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> Board[i][j];

            if (!Board[i][j])
                EmptyPosition.push_back(make_pair(i, j));
        }
    }
    EmptyPositionCount = EmptyPosition.size();

    // 완전 탐색을 통해 비어있는 곳에 숫자를 넣어 스도쿠 판 완성
    Bruteforce(0);

    return 0;
}