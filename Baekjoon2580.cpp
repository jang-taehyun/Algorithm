/*
Problem : ������ �ǿ� �ִ� ���ڵ��� ������ �־��� ��, ��� ��ĭ�� ä���� ����� ����ض�.
input : ������ �ǿ� �ִ� ���ڵ��� ����
output : ������ ���� �ϼ��� ���

idea
- ������ �� �� ����ִ� ��ġ(0���� �Էµ� ��ġ)�� ���� �����Ѵ�.
- ����ִ� ��ġ�� 1~9������ ���ڸ� ����ְ�, ���� ���ڰ� ����, ���ο�, 3*3 ���簢�� ���� �ִ��� Ȯ���Ѵ�.(promising ����)
- ���� ������� ���ڰ� ����, ���ο�, 3*3 ���簢�� ���� ���ٸ�, ����ִ� �ٸ� ��ġ�� 1~9������ ���ڸ� ����ְ� promising ������ Ȯ���Ѵ�.
*/
#include <iostream>
#include <vector>
using namespace std;

int Board[9][9];                            // �Էµ� ������ ��
vector<pair<int, int>> EmptyPosition;       // ����ִ� ��ġ�� ��Ƴ��� queue
                                            // first : column ��ǥ, second : row ��ǥ
int EmptyPositionCount;                     // ����ִ� ��ġ�� ����

bool Promising(int CheckX, int CheckY)
{
    // üũ�� ����
    int CheckNumber = Board[CheckX][CheckY];

    // column, row Ȯ��
    for (int i = 0; i < 9; i++)
    {
        if (Board[CheckX][i] == CheckNumber && i != CheckY)
            return false;
        if (Board[i][CheckY] == CheckNumber && i != CheckX)
            return false;
    }

    // 3*3 ���簢�� Ȯ��
    int StartX = (CheckX / 3) * 3;
    int StartY = (CheckY / 3) * 3;
    for (int i = StartX; i < StartX + 3; i++)
    {
        for (int j = StartY; j < StartY + 3; j++)
        {
            // ���� ������� ĭ�̶�� ���� ĭ�� Ȯ��
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
    // ���� ����ִ� ���� ���ڸ� ��� ä���־��ٸ�, �ϼ��� ������ ���� ����ϰ� ���α׷� ����
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

    // queue���� ����ִ� ��ǥ�� �ϳ� ������ 1~9���� ���� �� �ϳ��� �ְ�, promising ������ Ȯ���Ѵ�.
    int CurX = EmptyPosition[cnt].first;
    int CurY = EmptyPosition[cnt].second;
    for (int i = 1; i < 10; i++)
    {
        Board[CurX][CurY] = i;
        if (Promising(CurX, CurY))
            Bruteforce(cnt + 1);
    }

    // �� ä���� ��� ���󺹱�
    Board[CurX][CurY] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // ������ ���� �Է�
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

    // ���� Ž���� ���� ����ִ� ���� ���ڸ� �־� ������ �� �ϼ�
    Bruteforce(0);

    return 0;
}