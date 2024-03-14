/*
problem : n*n board를 상하좌우로 움직인 후 board에 나올 수 있는 숫자의 최대값을 구해라.
input : n*n board의 상태
output : 상하좌우로 움직인 후 board에서 나올 수 있는 숫자의 최대값

idea
- board의 상하좌우 움직임을 중복 수열로 5번 고른 후 탐색한다.
- 수열을 모두 골랐다면, board를 5번 움직여보고 그 중 최대값을 찾는다.

참고자료 : https://yabmoons.tistory.com/230
*/
#include <iostream>
#include <algorithm>
#define BOUND 5
using namespace std;

int Board[20][20];                // n*n board의 상태
int CopyBoard[20][20];            // 원본 board를 복사한 것 
int BoardLength;                  // board의 한 변의 길이
int SearchDirection[BOUND];       // 상하좌우 방향을 중복 수열로 고른 것
int MaximumNumber = 0;              // board에서 가장 큰 수

// board가 움직이는 방향을 정함
void ChooseDirection(int cnt);

// Board 복사
void CopyBoardFunc();

// board를 상하좌우로 움직임
void MoveUp();
void MoveDown();
void MoveLeft();
void MoveRight();

// board에서 최대 숫자를 return
int FindMaximumNumber();

int main()
{
    // board의 길이와 board의 정보 입력
    cin >> BoardLength;
    for (int i = 0; i < BoardLength; i++)
        for (int j = 0; j < BoardLength; j++)
            cin >> Board[i][j];

    // 움직이는 방향을 중복 수열로 골라 나올 수 있는 최대값을 구한다.
    ChooseDirection(0);

    // 결과값 출력
    cout << MaximumNumber;

    return 0;
}

int FindMaximumNumber()
{
    int tmp = CopyBoard[0][0];
    for (int i = 0; i < BoardLength; i++)
        for (int j = 0; j < BoardLength; j++)
            if (CopyBoard[i][j] > tmp)
                tmp = CopyBoard[i][j];

    return tmp;
}

void ChooseDirection(int cnt)
{
    // 모두 골랐다면 board를 복사하고,
    // 복사본으로 board를 움직인다.
    if (cnt >= BOUND)
    {
        CopyBoardFunc();

        for (int i = 0; i < BOUND; i++)
        {
            switch (SearchDirection[i])
            {
            case 0:
                MoveUp();
                break;
            case 1:
                MoveDown();
                break;
            case 2:
                MoveLeft();
                break;
            default:
                MoveRight();
                break;
            }
        }

        // 구해진 board에서 최대 숫자를 찾고 탐색 종료
        MaximumNumber = max(MaximumNumber, FindMaximumNumber());
        return;
    }

    // 상하좌우 방향 중 하나를 선택
    for (int i = 0; i < 4; i++)
    {
        SearchDirection[cnt] = i;
        ChooseDirection(cnt + 1);
    }
}

void CopyBoardFunc()
{
    for (int i = 0; i < BoardLength; i++)
        for (int j = 0; j < BoardLength; j++)
            CopyBoard[i][j] = Board[i][j];
}

void MoveUp()
{
    // Board의 숫자들을 합치지 않고 일단 이동
    bool IsFindNumber = false;
    for (int Column = 0; Column < BoardLength; Column++)
    {
        for (int Row = 0; Row < BoardLength; Row++)
        {
            IsFindNumber = false;

            // 만약 현재 자리가 비어있다면, 가장 가까운 숫자를 가져온다.
            if (!CopyBoard[Column][Row])
            {
                int Index = Column + 1;
                while (Index < BoardLength)
                {
                    if (CopyBoard[Index][Row])
                    {
                        IsFindNumber = true;
                        break;
                    }
                    Index++;
                }

                // 가장 가까운 숫자를 찾으면, 현재 자리에 찾은 숫자를 넣고
                // 가져온 숫자의 자리에는 0을 넣는다.
                if (IsFindNumber)
                {
                    CopyBoard[Column][Row] = CopyBoard[Index][Row];
                    CopyBoard[Index][Row] = 0;
                }
            }
        }
    }

    // Board에서 직전의 숫자를 비교해 같으면 합친다.
    for (int Column = 0; Column < BoardLength - 1; Column++)
    {
        for (int Row = 0; Row < BoardLength; Row++)
        {
            // 0이 아니면서, 두 숫자가 같다면
            if (CopyBoard[Column][Row] == CopyBoard[Column + 1][Row])
            {
                // 두 숫자를 합쳐서 현재 위치에 넣고,
                CopyBoard[Column][Row] += CopyBoard[Column + 1][Row];

                // 이전 위치는 0으로 만든다.
                CopyBoard[Column + 1][Row] = 0;
            }
        }
    }

    // Board의 숫자들 이동
    for (int Column = 0; Column < BoardLength; Column++)
    {
        for (int Row = 0; Row < BoardLength; Row++)
        {
            IsFindNumber = false;

            // 만약 현재 자리가 비어있다면, 가장 가까운 숫자를 가져온다.
            if (!CopyBoard[Column][Row])
            {
                int Index = Column + 1;
                while (Index < BoardLength)
                {
                    if (CopyBoard[Index][Row])
                    {
                        IsFindNumber = true;
                        break;
                    }
                    Index++;
                }

                // 가장 가까운 숫자를 찾으면, 현재 자리에 찾은 숫자를 넣고
                // 가져온 숫자의 자리에는 0을 넣는다.
                if (IsFindNumber)
                {
                    CopyBoard[Column][Row] = CopyBoard[Index][Row];
                    CopyBoard[Index][Row] = 0;
                }
            }
        }
    }
}

void MoveDown()
{
    // Board의 숫자들을 합치지 않고 일단 이동
    bool IsFindNumber = false;
    for (int Column = BoardLength - 1; Column >= 0; Column--)
    {
        for (int Row = 0; Row < BoardLength; Row++)
        {
            IsFindNumber = false;

            // 만약 현재 자리가 비어있다면, 가장 가까운 숫자를 가져온다.
            if (!CopyBoard[Column][Row])
            {
                int Index = Column - 1;
                while (Index >= 0)
                {
                    if (CopyBoard[Index][Row])
                    {
                        IsFindNumber = true;
                        break;
                    }
                    Index--;
                }

                // 가장 가까운 숫자를 찾으면, 현재 자리에 찾은 숫자를 넣고
                // 가져온 숫자의 자리에는 0을 넣는다.
                if (IsFindNumber)
                {
                    CopyBoard[Column][Row] = CopyBoard[Index][Row];
                    CopyBoard[Index][Row] = 0;
                }
            }
        }
    }

    // Board에서 직전의 숫자를 비교해 같으면 합친다.
    for (int Column = BoardLength - 1; Column > 0; Column--)
    {
        for (int Row = 0; Row < BoardLength; Row++)
        {
            // 0이 아니면서, 두 숫자가 같다면
            if (CopyBoard[Column][Row] == CopyBoard[Column - 1][Row])
            {
                // 두 숫자를 합쳐서 현재 위치에 넣고,
                CopyBoard[Column][Row] += CopyBoard[Column - 1][Row];

                // 이전 위치는 0으로 만든다.
                CopyBoard[Column - 1][Row] = 0;
            }
        }
    }

    // Board의 숫자들 이동
    for (int Column = BoardLength - 1; Column >= 0; Column--)
    {
        for (int Row = 0; Row < BoardLength; Row++)
        {
            IsFindNumber = false;

            // 만약 현재 자리가 비어있다면, 가장 가까운 숫자를 가져온다.
            if (!CopyBoard[Column][Row])
            {
                int Index = Column - 1;
                while (Index >= 0)
                {
                    if (CopyBoard[Index][Row])
                    {
                        IsFindNumber = true;
                        break;
                    }
                    Index--;
                }

                // 가장 가까운 숫자를 찾으면, 현재 자리에 찾은 숫자를 넣고
                // 가져온 숫자의 자리에는 0을 넣는다.
                if (IsFindNumber)
                {
                    CopyBoard[Column][Row] = CopyBoard[Index][Row];
                    CopyBoard[Index][Row] = 0;
                }
            }
        }
    }
}

void MoveLeft()
{
    // Board의 숫자들을 합치지 않고 일단 이동
    bool IsFindNumber = false;
    for (int Row = 0; Row < BoardLength; Row++)
    {
        for (int Column = 0; Column < BoardLength; Column++)
        {
            IsFindNumber = false;

            // 만약 현재 자리가 비어있다면, 가장 가까운 숫자를 가져온다.
            if (!CopyBoard[Column][Row])
            {
                int Index = Row + 1;
                while (Index < BoardLength)
                {
                    if (CopyBoard[Column][Index])
                    {
                        IsFindNumber = true;
                        break;
                    }
                    Index++;
                }

                // 가장 가까운 숫자를 찾으면, 현재 자리에 찾은 숫자를 넣고
                // 가져온 숫자의 자리에는 0을 넣는다.
                if (IsFindNumber)
                {
                    CopyBoard[Column][Row] = CopyBoard[Column][Index];
                    CopyBoard[Column][Index] = 0;
                }
            }
        }
    }

    // Board에서 직전의 숫자를 비교해 같으면 합친다.
    for (int Row = 0; Row < BoardLength - 1; Row++)
    {
        for (int Column = 0; Column < BoardLength; Column++)
        {
            // 0이 아니면서, 두 숫자가 같다면
            if (CopyBoard[Column][Row] == CopyBoard[Column][Row + 1])
            {
                // 두 숫자를 합쳐서 현재 위치에 넣고,
                CopyBoard[Column][Row] += CopyBoard[Column][Row + 1];

                // 이전 위치는 0으로 만든다.
                CopyBoard[Column][Row + 1] = 0;
            }
        }
    }

    // Board의 숫자들 이동
    for (int Row = 0; Row < BoardLength; Row++)
    {
        for (int Column = 0; Column < BoardLength; Column++)
        {
            IsFindNumber = false;

            // 만약 현재 자리가 비어있다면, 가장 가까운 숫자를 가져온다.
            if (!CopyBoard[Column][Row])
            {
                int Index = Row + 1;
                while (Index < BoardLength)
                {
                    if (CopyBoard[Column][Index])
                    {
                        IsFindNumber = true;
                        break;
                    }
                    Index++;
                }

                // 가장 가까운 숫자를 찾으면, 현재 자리에 찾은 숫자를 넣고
                // 가져온 숫자의 자리에는 0을 넣는다.
                if (IsFindNumber)
                {
                    CopyBoard[Column][Row] = CopyBoard[Column][Index];
                    CopyBoard[Column][Index] = 0;
                }
            }
        }
    }
}

void MoveRight()
{
    // Board의 숫자들을 합치지 않고 일단 이동
    bool IsFindNumber = false;
    for (int Row = BoardLength - 1; Row >= 0; Row--)
    {
        for (int Column = 0; Column < BoardLength; Column++)
        {
            IsFindNumber = false;

            // 만약 현재 자리가 비어있다면, 가장 가까운 숫자를 가져온다.
            if (!CopyBoard[Column][Row])
            {
                int Index = Row - 1;
                while (Index >= 0)
                {
                    if (CopyBoard[Column][Index])
                    {
                        IsFindNumber = true;
                        break;
                    }
                    Index--;
                }

                // 가장 가까운 숫자를 찾으면, 현재 자리에 찾은 숫자를 넣고
                // 가져온 숫자의 자리에는 0을 넣는다.
                if (IsFindNumber)
                {
                    CopyBoard[Column][Row] = CopyBoard[Column][Index];
                    CopyBoard[Column][Index] = 0;
                }
            }
        }
    }

    // Board에서 직전의 숫자를 비교해 같으면 합친다.
    for (int Row = BoardLength - 1; Row > 0; Row--)
    {
        for (int Column = 0; Column < BoardLength; Column++)
        {
            // 0이 아니면서, 두 숫자가 같다면
            if (CopyBoard[Column][Row] == CopyBoard[Column][Row - 1])
            {
                // 두 숫자를 합쳐서 현재 위치에 넣고,
                CopyBoard[Column][Row] += CopyBoard[Column][Row - 1];

                // 이전 위치는 0으로 만든다.
                CopyBoard[Column][Row - 1] = 0;
            }
        }
    }

    // Board의 숫자들 이동
    for (int Row = BoardLength - 1; Row >= 0; Row--)
    {
        for (int Column = 0; Column < BoardLength; Column++)
        {
            IsFindNumber = false;

            // 만약 현재 자리가 비어있다면, 가장 가까운 숫자를 가져온다.
            if (!CopyBoard[Column][Row])
            {
                int Index = Row - 1;
                while (Index >= 0)
                {
                    if (CopyBoard[Column][Index])
                    {
                        IsFindNumber = true;
                        break;
                    }
                    Index--;
                }

                // 가장 가까운 숫자를 찾으면, 현재 자리에 찾은 숫자를 넣고
                // 가져온 숫자의 자리에는 0을 넣는다.
                if (IsFindNumber)
                {
                    CopyBoard[Column][Row] = CopyBoard[Column][Index];
                    CopyBoard[Column][Index] = 0;
                }
            }
        }
    }
}