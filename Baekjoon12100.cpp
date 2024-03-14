/*
problem : n*n board�� �����¿�� ������ �� board�� ���� �� �ִ� ������ �ִ밪�� ���ض�.
input : n*n board�� ����
output : �����¿�� ������ �� board���� ���� �� �ִ� ������ �ִ밪

idea
- board�� �����¿� �������� �ߺ� ������ 5�� �� �� Ž���Ѵ�.
- ������ ��� ����ٸ�, board�� 5�� ���������� �� �� �ִ밪�� ã�´�.

�����ڷ� : https://yabmoons.tistory.com/230
*/
#include <iostream>
#include <algorithm>
#define BOUND 5
using namespace std;

int Board[20][20];                // n*n board�� ����
int CopyBoard[20][20];            // ���� board�� ������ �� 
int BoardLength;                  // board�� �� ���� ����
int SearchDirection[BOUND];       // �����¿� ������ �ߺ� ������ �� ��
int MaximumNumber = 0;              // board���� ���� ū ��

// board�� �����̴� ������ ����
void ChooseDirection(int cnt);

// Board ����
void CopyBoardFunc();

// board�� �����¿�� ������
void MoveUp();
void MoveDown();
void MoveLeft();
void MoveRight();

// board���� �ִ� ���ڸ� return
int FindMaximumNumber();

int main()
{
    // board�� ���̿� board�� ���� �Է�
    cin >> BoardLength;
    for (int i = 0; i < BoardLength; i++)
        for (int j = 0; j < BoardLength; j++)
            cin >> Board[i][j];

    // �����̴� ������ �ߺ� ������ ��� ���� �� �ִ� �ִ밪�� ���Ѵ�.
    ChooseDirection(0);

    // ����� ���
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
    // ��� ����ٸ� board�� �����ϰ�,
    // ���纻���� board�� �����δ�.
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

        // ������ board���� �ִ� ���ڸ� ã�� Ž�� ����
        MaximumNumber = max(MaximumNumber, FindMaximumNumber());
        return;
    }

    // �����¿� ���� �� �ϳ��� ����
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
    // Board�� ���ڵ��� ��ġ�� �ʰ� �ϴ� �̵�
    bool IsFindNumber = false;
    for (int Column = 0; Column < BoardLength; Column++)
    {
        for (int Row = 0; Row < BoardLength; Row++)
        {
            IsFindNumber = false;

            // ���� ���� �ڸ��� ����ִٸ�, ���� ����� ���ڸ� �����´�.
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

                // ���� ����� ���ڸ� ã����, ���� �ڸ��� ã�� ���ڸ� �ְ�
                // ������ ������ �ڸ����� 0�� �ִ´�.
                if (IsFindNumber)
                {
                    CopyBoard[Column][Row] = CopyBoard[Index][Row];
                    CopyBoard[Index][Row] = 0;
                }
            }
        }
    }

    // Board���� ������ ���ڸ� ���� ������ ��ģ��.
    for (int Column = 0; Column < BoardLength - 1; Column++)
    {
        for (int Row = 0; Row < BoardLength; Row++)
        {
            // 0�� �ƴϸ鼭, �� ���ڰ� ���ٸ�
            if (CopyBoard[Column][Row] == CopyBoard[Column + 1][Row])
            {
                // �� ���ڸ� ���ļ� ���� ��ġ�� �ְ�,
                CopyBoard[Column][Row] += CopyBoard[Column + 1][Row];

                // ���� ��ġ�� 0���� �����.
                CopyBoard[Column + 1][Row] = 0;
            }
        }
    }

    // Board�� ���ڵ� �̵�
    for (int Column = 0; Column < BoardLength; Column++)
    {
        for (int Row = 0; Row < BoardLength; Row++)
        {
            IsFindNumber = false;

            // ���� ���� �ڸ��� ����ִٸ�, ���� ����� ���ڸ� �����´�.
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

                // ���� ����� ���ڸ� ã����, ���� �ڸ��� ã�� ���ڸ� �ְ�
                // ������ ������ �ڸ����� 0�� �ִ´�.
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
    // Board�� ���ڵ��� ��ġ�� �ʰ� �ϴ� �̵�
    bool IsFindNumber = false;
    for (int Column = BoardLength - 1; Column >= 0; Column--)
    {
        for (int Row = 0; Row < BoardLength; Row++)
        {
            IsFindNumber = false;

            // ���� ���� �ڸ��� ����ִٸ�, ���� ����� ���ڸ� �����´�.
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

                // ���� ����� ���ڸ� ã����, ���� �ڸ��� ã�� ���ڸ� �ְ�
                // ������ ������ �ڸ����� 0�� �ִ´�.
                if (IsFindNumber)
                {
                    CopyBoard[Column][Row] = CopyBoard[Index][Row];
                    CopyBoard[Index][Row] = 0;
                }
            }
        }
    }

    // Board���� ������ ���ڸ� ���� ������ ��ģ��.
    for (int Column = BoardLength - 1; Column > 0; Column--)
    {
        for (int Row = 0; Row < BoardLength; Row++)
        {
            // 0�� �ƴϸ鼭, �� ���ڰ� ���ٸ�
            if (CopyBoard[Column][Row] == CopyBoard[Column - 1][Row])
            {
                // �� ���ڸ� ���ļ� ���� ��ġ�� �ְ�,
                CopyBoard[Column][Row] += CopyBoard[Column - 1][Row];

                // ���� ��ġ�� 0���� �����.
                CopyBoard[Column - 1][Row] = 0;
            }
        }
    }

    // Board�� ���ڵ� �̵�
    for (int Column = BoardLength - 1; Column >= 0; Column--)
    {
        for (int Row = 0; Row < BoardLength; Row++)
        {
            IsFindNumber = false;

            // ���� ���� �ڸ��� ����ִٸ�, ���� ����� ���ڸ� �����´�.
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

                // ���� ����� ���ڸ� ã����, ���� �ڸ��� ã�� ���ڸ� �ְ�
                // ������ ������ �ڸ����� 0�� �ִ´�.
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
    // Board�� ���ڵ��� ��ġ�� �ʰ� �ϴ� �̵�
    bool IsFindNumber = false;
    for (int Row = 0; Row < BoardLength; Row++)
    {
        for (int Column = 0; Column < BoardLength; Column++)
        {
            IsFindNumber = false;

            // ���� ���� �ڸ��� ����ִٸ�, ���� ����� ���ڸ� �����´�.
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

                // ���� ����� ���ڸ� ã����, ���� �ڸ��� ã�� ���ڸ� �ְ�
                // ������ ������ �ڸ����� 0�� �ִ´�.
                if (IsFindNumber)
                {
                    CopyBoard[Column][Row] = CopyBoard[Column][Index];
                    CopyBoard[Column][Index] = 0;
                }
            }
        }
    }

    // Board���� ������ ���ڸ� ���� ������ ��ģ��.
    for (int Row = 0; Row < BoardLength - 1; Row++)
    {
        for (int Column = 0; Column < BoardLength; Column++)
        {
            // 0�� �ƴϸ鼭, �� ���ڰ� ���ٸ�
            if (CopyBoard[Column][Row] == CopyBoard[Column][Row + 1])
            {
                // �� ���ڸ� ���ļ� ���� ��ġ�� �ְ�,
                CopyBoard[Column][Row] += CopyBoard[Column][Row + 1];

                // ���� ��ġ�� 0���� �����.
                CopyBoard[Column][Row + 1] = 0;
            }
        }
    }

    // Board�� ���ڵ� �̵�
    for (int Row = 0; Row < BoardLength; Row++)
    {
        for (int Column = 0; Column < BoardLength; Column++)
        {
            IsFindNumber = false;

            // ���� ���� �ڸ��� ����ִٸ�, ���� ����� ���ڸ� �����´�.
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

                // ���� ����� ���ڸ� ã����, ���� �ڸ��� ã�� ���ڸ� �ְ�
                // ������ ������ �ڸ����� 0�� �ִ´�.
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
    // Board�� ���ڵ��� ��ġ�� �ʰ� �ϴ� �̵�
    bool IsFindNumber = false;
    for (int Row = BoardLength - 1; Row >= 0; Row--)
    {
        for (int Column = 0; Column < BoardLength; Column++)
        {
            IsFindNumber = false;

            // ���� ���� �ڸ��� ����ִٸ�, ���� ����� ���ڸ� �����´�.
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

                // ���� ����� ���ڸ� ã����, ���� �ڸ��� ã�� ���ڸ� �ְ�
                // ������ ������ �ڸ����� 0�� �ִ´�.
                if (IsFindNumber)
                {
                    CopyBoard[Column][Row] = CopyBoard[Column][Index];
                    CopyBoard[Column][Index] = 0;
                }
            }
        }
    }

    // Board���� ������ ���ڸ� ���� ������ ��ģ��.
    for (int Row = BoardLength - 1; Row > 0; Row--)
    {
        for (int Column = 0; Column < BoardLength; Column++)
        {
            // 0�� �ƴϸ鼭, �� ���ڰ� ���ٸ�
            if (CopyBoard[Column][Row] == CopyBoard[Column][Row - 1])
            {
                // �� ���ڸ� ���ļ� ���� ��ġ�� �ְ�,
                CopyBoard[Column][Row] += CopyBoard[Column][Row - 1];

                // ���� ��ġ�� 0���� �����.
                CopyBoard[Column][Row - 1] = 0;
            }
        }
    }

    // Board�� ���ڵ� �̵�
    for (int Row = BoardLength - 1; Row >= 0; Row--)
    {
        for (int Column = 0; Column < BoardLength; Column++)
        {
            IsFindNumber = false;

            // ���� ���� �ڸ��� ����ִٸ�, ���� ����� ���ڸ� �����´�.
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

                // ���� ����� ���ڸ� ã����, ���� �ڸ��� ã�� ���ڸ� �ְ�
                // ������ ������ �ڸ����� 0�� �ִ´�.
                if (IsFindNumber)
                {
                    CopyBoard[Column][Row] = CopyBoard[Column][Index];
                    CopyBoard[Column][Index] = 0;
                }
            }
        }
    }
}