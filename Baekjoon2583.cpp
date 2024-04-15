/*
problem : n*m board�� ���� �ٸ� ũ�⸦ ���� ���簢������ ������ �������� �ʴ� ������ ������ ũ�⸦ ���ض�.
input : n*m board�� ũ��, ���� �ٸ� ũ�⸦ ���� ���簢���� �����ϴ� 2���� ������
output : n*m board�� ���� �ٸ� ũ�⸦ ���� ���簢������ ������ �������� �ʴ� ������ ������ ũ��

idea
- ���� �ٸ� ũ�⸦ ���� ���簢���� �������� ������ �Է¹��� ��,
  ������ x, y ��ǥ�� -1�� �ϰ� ������ ���� ĭ���� ��� �����Ѵ�.
- n*m board�� BFS�� Ž���� �и��� ������ ������ ũ�⸦ ���Ѵ�.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int Column, Row;                    // board�� column, row�� ����
bool Board[101][101];               // n*m board
                                    // 0 : �湮���� ����, 1 : ������ ĭ �Ǵ� �̹� count�� ĭ
int dx[4] = { 0, 0, -1, 1 };          // �̵� ����
int dy[4] = { -1, 1, 0, 0 };

bool Promising(int x, int y)
{
    if (x < 0 || x >= Column || y < 0 || y >= Row)
        return false;
    if (Board[x][y])
        return false;
    return true;
}

int BFS(int sx, int sy)
{
    queue<pair<int, int>> next;        // ������ Ž���� ĭ��
    int cx, cy, nx, ny;                // ���� ��ġ, ���� ��ġ
    int cnt = 1;

    next.push(make_pair(sx, sy));
    Board[sx][sy] = true;

    while (!next.empty())
    {
        cx = next.front().first;
        cy = next.front().second;
        next.pop();

        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (!Promising(nx, ny))
                continue;

            cnt++;
            Board[nx][ny] = true;
            next.push(make_pair(nx, ny));
        }
    }

    return cnt;
}

int main()
{
    vector<int> Size;                // �������� �ʴ� ������ ũ���
    int sx, sy, lx, ly;              // ������, ����
    int cnt;                         // ������ �簢���� ����

    // n*m board ���� �� ������ �簢������ ���� �Է�
    cin >> Column >> Row >> cnt;
    while (cnt--)
    {
        cin >> sy >> sx >> ly >> lx;
        lx -= 1;
        ly -= 1;

        for (int i = sx; i <= lx; i++)
            for (int j = sy; j <= ly; j++)
                Board[i][j] = true;
    }

    // board�� BFS Ž��
    for (int i = 0; i < Column; i++)
        for (int j = 0; j < Row; j++)
            if (!Board[i][j])
                Size.push_back(BFS(i, j));

    // ������������ sort
    sort(Size.begin(), Size.end());

    // ����� ���
    cout << Size.size() << ' ';
    for (int i = 0; i < Size.size(); i++)
        cout << Size[i] << ' ';

    return 0;
}