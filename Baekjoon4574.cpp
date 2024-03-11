/*
problem : 9*9 board�� 1~9���� ������ ��ġ�� �־��� ��, ���� �ٸ� ������ ������ �̷���� ���̳븦 �̿��� board�� ä��� ��츦 ���ض�.
input : 9*9 board�� ����
output : ���� �ٸ� ������ ������ board�� ä�� ���

idea
- board���� ����ִ� ���� ã�´�.
- ����ִ� ���� �� ��� �Ǵ� �� ��� ���̳븦 �ִ´�.
- ���̳븦 ���� �� ����, ���ο�, 3*3 ���簢���� ���� ���ڰ� �ִ� �� Ȯ���Ѵ�.(promising ����)
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int Board[9][9];                // board�� ����
bool IsFillBoard = false;         // board�� ��� ä�������� ����
bool IsExist[10][10];           // (i, j) ���̳밡 �����ϴ��� ����

void Init()
{
    IsFillBoard = false;
    memset(IsExist, false, sizeof(IsExist));
    memset(Board, false, sizeof(Board));
}

bool Promising(int _x, int _y)
{
    int CheckNumber = Board[_x][_y];

    // ����, ���ο� Ȯ��
    for (int i = 0; i < 9; i++)
    {
        if (Board[i][_y] == CheckNumber && i != _x)
            return false;
        if (Board[_x][i] == CheckNumber && i != _y)
            return false;
    }

    // 3*3 ���簢�� Ȯ��
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
    // ��� �ִ� ĭ�� ã�´�.
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

    // ���� board�� ��� ä���ٸ�, ä���� board�� ����� ����ϰ� Ž�� ����
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

    // �� ĭ�� ���̳븦 �ϳ� ���´�.
    for (int i = 1; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            // �̹� �����ϴ� ���̳��̰ų� �� ���� ���ڰ� ���ٸ� �ٸ� ���̳븦 ���´�.
            if (IsExist[i][j] || i == j)
                continue;

            // board�� ���̳븦 ���´�.
            IsExist[i][j] = true;
            IsExist[j][i] = true;

            // board�� �� ��� ���̳븦 ���� promising���� Ȯ��
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

                // board�� ���� ���̳븦 �����Ѵ�.(���� ����)
                Board[cx][cy] = 0;
                Board[cx + 1][cy] = 0;
            }

            // board�� �� ��� ���̳븦 ���� promising���� Ȯ��
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

                // board�� ���� ���̳븦 �����Ѵ�.(���� ����)
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
    int TestCount = 1;                            // �׽�Ʈ�� Ƚ��
    int ExistDominoCount;                       // board�� �̹� �����ϴ� ���̳��� ����
    int Number1, Number2;                       // ���̳뿡 ���� 2���� ����
    string DominoPosition1, DominoPosition2;    // ���̳��� 2���� ���ڰ� ������ ��ġ

    while (1)
    {
        // 9*9 board�� �̹� ������ ���̳� ������ �Է�
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

        // 9*9 board�� �̹� ������ ���� ���� ���� �Է�
        for (int i = 1; i < 10; i++)
        {
            cin >> DominoPosition1;
            Board[DominoPosition1[0] - 'A'][DominoPosition1[1] - '1'] = i;
        }

        // brute force�� �̿��� 9*9 board�� ä���.
        cout << "Puzzle " << TestCount << '\n';
        Bruteforce();

        // 9*9 board �� ����� domino �ʱ�ȭ
        Init();
        TestCount++;
    }

    return 0;
}