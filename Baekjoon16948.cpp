/*
problem : k*k board���� (n, m)ĭ�� �ִ� ��������Ʈ�� (x, y)�� �̵��� ��, ��������Ʈ�� �ּ� �̵� Ƚ���� ���ض�.
input : ������(n, m), ������(x, y), board�� ũ��(k)
output : (n, m)���� ������ (x, y)�� �����ϴ� �ּ� �̵� Ƚ��

idea
- (n, m)�� root�̰�, level�� �̵� Ƚ��, node�� ������ �� ����� ��Ÿ���� tree�� �����.
- tree�� BFS ������� Ž���Ѵ�.
- ���� ������ Ž���� ĭ�̶�� �� �̻� Ž������ �ʴ´�.
- (x, y)�� �����ϸ� level�� return
*/
#include <iostream>
#include <queue>
using namespace std;

bool Search[200][200];                // �ش� ĭ�� Ž���ߴ��� ����
int BoardLength;                      // board�� �� ���� ����
int dx[6] = { -2, -2, 0, 0, 2, 2 };     // �̵� ����
int dy[6] = { -1, 1, -2, 2, -1, 1 };

int BFS(int sx, int sy, int ex, int ey)
{
    queue<pair<int, int>> next;       // ������ Ž���� ĭ
    int QueueSize;                    // queue�� ũ��
    int MoveCount = 0;                  // ������ Ƚ��
    int CurX, CurY, NextX, NextY;     // ���� Ž���ϰ� �ִ� ĭ, ������ Ž���� ĭ

    // �������� Ž�� ǥ���ϰ� queue�� �ִ´�.
    Search[sx][sy] = true;
    next.push(make_pair(sx, sy));

    while (!next.empty())
    {
        // queue�� ũ�⸸ŭ �ݺ�
        QueueSize = next.size();
        for (int i = 0; i < QueueSize; i++)
        {
            // queue���� ��ǥ �ϳ��� ������ Ž��
            CurX = next.front().first;
            CurY = next.front().second;
            next.pop();

            // �������� �����ߴٸ� ���� level return
            if (CurX == ex && CurY == ey)
                return MoveCount;

            // �̵��� ĭ �� ���� Ž������ �ʴ� ĭ�� queue�� �ִ´�.
            for (int j = 0; j < 6; j++)
            {
                NextX = CurX + dx[j];
                NextY = CurY + dy[j];

                // ���� �� Ž�� ���� �˻�
                if (NextX < 0 || NextX >= BoardLength || NextY < 0 || NextY >= BoardLength)
                    continue;
                if (Search[NextX][NextY])
                    continue;

                Search[NextX][NextY] = true;
                next.push(make_pair(NextX, NextY));
            }
        }

        // �� level�� ��� Ž�������Ƿ� level ���� 
        MoveCount++;
    }

    // �̵��� �� ���ٸ� -1�� return
    return -1;
}

int main()
{
    int sx, sy, ex, ey;

    // board�� �� ���� ���� �� ������, ������ �Է�
    cin >> BoardLength;
    cin >> sx >> sy >> ex >> ey;

    // tree�� BFS ������� Ž���� �ּ� �̵� Ƚ���� ���Ѵ�.
    cout << BFS(sx, sy, ex, ey);

    return 0;
}