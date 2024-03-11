/*
problem : n*m board�� �� ĭ���� ���ĺ� �빮�ڰ� ������, (1, 1)�������� �����Ͽ� ���� �ٸ� ���ĺ��� �����鼭 �̵��� �� �ִ� ĭ�� �ִ� ����
input : n*m board�� ����
output : (1, 1)���� ������ ���� �ٸ� ���ĺ��� �����鼭 �̵��� �� �ִ� ĭ�� �ִ� ����

idea
- (1, 1)�������� ������ DFS ������� Ž���Ѵ�.
- Ž���� ������ �ִ밪�� update
- ���� �̹� ������ ĭ�� �����ϴ� ���, Ž�� ����
- ���� ���̻� �̵��� �� ���� ���, Ž�� ����
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int Column, Row;            // board�� ����, ���� ����
char Board[20][20];         // board�� �� ĭ�� ������ ���ĺ� �빮��
bool visited[20][20];       // board�� �� ĭ�� �湮 ����
bool IsPass[26];            // ���ĺ��� ���������� ����

int dx[4] = { 0, 0, -1, 1 };  // �̵��� �� �ִ� ����
int dy[4] = { -1, 1, 0, 0 };

int MaximumPassLength = 1;    // ������ �� �ִ� ĭ�� �ִ� ����

void DFS(int cx, int cy, int count)
{
    // �ִ밪 update
    MaximumPassLength = max(MaximumPassLength, count);

    // 4���� �� �ϳ��� ������ �̵��Ѵ�.
    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        nx = cx + dx[i];
        ny = cy + dy[i];

        // ����, �湮 ����, �̹� ���� ���ĺ����� �˻�
        if (nx < 0 || nx >= Column || ny < 0 || ny >= Row)
            continue;
        if (visited[nx][ny])
            continue;
        if (IsPass[Board[nx][ny] - 'A'])
            continue;

        // �ش� ĭ�� �̵�
        visited[nx][ny] = true;
        IsPass[Board[nx][ny] - 'A'] = true;
        DFS(nx, ny, count + 1);

        // ���󺹱�
        visited[nx][ny] = false;
        IsPass[Board[nx][ny] - 'A'] = false;
    }
}

int main()
{
    string input;
    int nx, ny;

    // board�� ���� �Է�
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;
        for (int j = 0; j < Row; j++)
            Board[i][j] = input[j];
    }

    // (1, 1)���� ������ DFS ������� board�� Ž���Ͽ� �ִ밪�� ���Ѵ�.
    visited[0][0] = true;
    IsPass[Board[0][0] - 'A'] = true;
    DFS(0, 0, 1);

    // ����� ���
    cout << MaximumPassLength;

    return 0;
}