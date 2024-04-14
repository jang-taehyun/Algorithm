/*
problem : n*m board���� 1�� ĭ�� ��� 0���� �ٲ�µ� �ɸ��� �ð��� ��� 0���� �ٲ�� ���� �ð��� �����ִ� 1�� ĭ�� ������ ���ض�.
input : n*m board
output : board���� 1�� ĭ�� ��� 0���� �ٲ�µ� �ɸ��� �ð�, ��� 0���� �ٲ�� ���� �ð��� �����ִ� 1�� ĭ�� ����

idea
- board�� root�� (0, 0), node�� �̵� ���� ĭ�� ��ġ�� ĭ�� ����(0 �Ǵ� 1)�� tree�� �����.
- tree�� BFS ������� Ž���Ѵ�.
- non-promising ����
  1) �̹� �湮�ߴ� ĭ�� �ٽ� �湮�ϴ� ���, board�� ������ ����� ���
  2) �湮�� ĭ�� ���°� 1�� ��� -> �湮�� ĭ�� ���¸� 0���� ����� count�� ����.
      -> ���⼭ �� count�� Ž���� ��� ������ �� ��° output���� ����Ѵ�.
- tree�� ��� Ž���� ������ Ž���� �ݺ��ϰ�, (�ݺ��� Ƚ��-1)�� ù output���� ����Ѵ�.

https://ongveloper.tistory.com/159
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool Tree[100][100];            // Tree
int Column, Row;                // board�� column, row
bool visited[100][100];         // ���� ĭ�� �湮 ����
int RemoveCount;                // Ž���� �� 0���� �ٲ� ĭ�� ����
int dx[4] = { 0, 0, 1, -1 };      // Ž�� ����
int dy[4] = { 1, -1, 0, 0 };

bool IsAbleSearch(int x, int y)
{
    if (x < 0 || x >= Column || y < 0 || y >= Row)
        return false;
    if (visited[x][y])
        return false;
    return true;
}

bool BFS()
{
    queue<pair<int, int>> next;        // ������ Ž���� ĭ��
    int cx, cy, nx, ny;                // ���� ��ġ, ���� ��ġ
    int cnt = 0;

    next.push(make_pair(0, 0));
    visited[0][0] = true;

    // Ž��
    while (!next.empty())
    {
        cx = next.front().first;
        cy = next.front().second;
        next.pop();

        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (IsAbleSearch(nx, ny))
            {
                visited[nx][ny] = true;

                // ���� ĭ�� 1�� ���
                if (Tree[nx][ny])
                {
                    Tree[nx][ny] = false;
                    cnt++;
                }
                // ���� ĭ�� 0�� ���
                else
                {
                    next.push(make_pair(nx, ny));
                }
            }
        }
    }

    // 1�� �ٲ� ĭ�� ���� ���, false ��ȯ
    if (!cnt)
        return false;

    // 1�� �ٲ� ĭ�� �ϳ��� ������,
    // 2��° output�� update�� true ��ȯ
    RemoveCount = cnt;
    return true;
}

int main()
{
    int loopCount = 0;                // BFS Ž���� �õ��� Ƚ��

    // n*m board �Է�
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
        for (int j = 0; j < Row; j++)
            cin >> Tree[i][j];

    // BFS Ž��
    while (BFS())
    {
        loopCount++;
        memset(visited, false, sizeof(visited));
    }

    // ����� ���
    cout << loopCount << ' ' << RemoveCount;

    return 0;
}