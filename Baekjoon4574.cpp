/*
problem : 9*9 board에 1~9까지 숫자의 위치가 주어질 때, 서로 다른 숫자의 쌍으로 이루어진 도미노를 이용해 board를 채우는 경우를 구해라.
input : 9*9 board의 정보
output : 서로 다른 숫자의 쌍으로 board를 채운 모습

idea
- board에서 비어있는 곳을 찾는다.
- 비어있는 곳에 ㅣ 모양 또는 ㅡ 모양 도미노를 넣는다.
- 도미노를 놓은 후 가로, 세로열, 3*3 정사각형에 같은 숫자가 있는 지 확인한다.(promising 조건)
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int Board[9][9];                // board의 정보
bool IsFillBoard = false;         // board가 모두 채워졌는지 여부
bool IsExist[10][10];           // (i, j) 도미노가 존재하는지 여부

void Init()
{
    IsFillBoard = false;
    memset(IsExist, false, sizeof(IsExist));
    memset(Board, false, sizeof(Board));
}

bool Promising(int _x, int _y)
{
    int CheckNumber = Board[_x][_y];

    // 가로, 세로열 확인
    for (int i = 0; i < 9; i++)
    {
        if (Board[i][_y] == CheckNumber && i != _x)
            return false;
        if (Board[_x][i] == CheckNumber && i != _y)
            return false;
    }

    // 3*3 정사각형 확인
    int StartX = (_x / 3) * 3;
    int StartY = (_y / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (StartX + i == _x && StartY + j == _y)
                continue;

            if (Board[StartX + i][StartY + j] == CheckNumber)
                return false;
        }
    }

    return true;
}

void Bruteforce()
{
    // 비어 있는 칸을 찾는다.
    int cx = -1, cy;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!Board[i][j])
            {
                cx = i;
                cy = j;
                break;
            }
        }

        if (cx != -1)
            break;
    }

    // 만약 board를 모두 채웠다면, 채워진 board의 모습을 출력하고 탐색 종료
    if (cx == -1)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << Board[i][j];
            cout << '\n';
        }
        IsFillBoard = true;

        return;
    }

    // 빈 칸에 도미노를 하나 놓는다.
    for (int i = 1; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            // 이미 존재하는 도미노이거나 두 쌍의 숫자가 같다면 다른 도미노를 놓는다.
            if (IsExist[i][j] || i == j)
                continue;

            // board에 도미노를 놓는다.
            IsExist[i][j] = true;
            IsExist[j][i] = true;

            // board에 ㅣ 모양 도미노를 놓아 promising인지 확인
            if (cx + 1 < 9 && !Board[cx + 1][cy])
            {
                Board[cx][cy] = i;
                Board[cx + 1][cy] = j;
                if (Promising(cx, cy) && Promising(cx + 1, cy))
                    Bruteforce();
                if (IsFillBoard)
                    return;

                Board[cx][cy] = j;
                Board[cx + 1][cy] = i;
                if (Promising(cx, cy) && Promising(cx + 1, cy))
                    Bruteforce();
                if (IsFillBoard)
                    return;

                // board에 놓은 도미노를 제거한다.(원상 복구)
                Board[cx][cy] = 0;
                Board[cx + 1][cy] = 0;
            }

            // board에 ㅡ 모양 도미노를 놓아 promising인지 확인
            if (cy + 1 < 9 && !Board[cx][cy + 1])
            {
                Board[cx][cy] = i;
                Board[cx][cy + 1] = j;
                if (Promising(cx, cy) && Promising(cx, cy + 1))
                    Bruteforce();
                if (IsFillBoard)
                    return;
                Board[cx][cy] = j;
                Board[cx][cy + 1] = i;
                if (Promising(cx, cy) && Promising(cx, cy + 1))
                    Bruteforce();
                if (IsFillBoard)
                    return;

                // board에 놓은 도미노를 제거한다.(원상 복구)
                Board[cx][cy] = 0;
                Board[cx][cy + 1] = 0;
            }

            IsExist[i][j] = false;
            IsExist[j][i] = false;
        }
    }
}

int main()
{
    int TestCount = 1;                            // 테스트한 횟수
    int ExistDominoCount;                       // board에 이미 존재하는 도미노의 개수
    int Number1, Number2;                       // 도미노에 적힌 2쌍의 숫자
    string DominoPosition1, DominoPosition2;    // 도미노의 2쌍의 숫자가 놓여진 위치

    while (1)
    {
        // 9*9 board에 이미 놓아진 도미노 정보를 입력
        cin >> ExistDominoCount;
        if (!ExistDominoCount)
            break;
        for (int i = 0; i < ExistDominoCount; i++)
        {
            cin >> Number1 >> DominoPosition1 >> Number2 >> DominoPosition2;

            Board[DominoPosition1[0] - 'A'][DominoPosition1[1] - '1'] = Number1;
            Board[DominoPosition2[0] - 'A'][DominoPosition2[1] - '1'] = Number2;

            IsExist[Number1][Number2] = true;
            IsExist[Number2][Number1] = true;
        }

        // 9*9 board에 이미 놓아진 단일 숫자 정보 입력
        for (int i = 1; i < 10; i++)
        {
            cin >> DominoPosition1;
            Board[DominoPosition1[0] - 'A'][DominoPosition1[1] - '1'] = i;
        }

        // brute force를 이용해 9*9 board를 채운다.
        cout << "Puzzle " << TestCount << '\n';
        Bruteforce();

        // 9*9 board 및 사용한 domino 초기화
        Init();
        TestCount++;
    }

    return 0;
}