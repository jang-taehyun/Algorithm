/*
problem : n*m board�� �ִ� ���� �ִ� ĭ����, �� ���� �μ��� �̵��� �� �ִ� ĭ�� ������ ���ض�.
input : n*m board
output : �� ���� �ִ� ĭ�������� ������ �̵��� �� �ִ� ĭ�� ����

idea
- board�� ���� ����� ��ĭ(0�� ĭ)�� BFS ������� ��ȣ�� ���̰�, vector�� �� ĭ�� ������ ����
- ��(1�� ĭ)���� �����¿츦 Ž���� ����� ��ĭ�� ������ ���Ѵ�.

���� �ڷ� : https://yabmoons.tistory.com/216
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 1000
#define INIT 2
using namespace std;

int Column, Row;                        // board�� column, row
int Board[MAX][MAX];                    // board
int CopyBoard[MAX][MAX];                // ����� board(���� ��¿�)
vector<int> EmptySpace;                 // board���� ���� ����� ��ĭ�� ����
                                        // index : �� ĭ�� ��ȣ
int EmptySpaceCount = INIT;               // ��ĭ ��ȣ�� ����
int dx[4] = { 0, 0, 1, -1 };              // �̵� ����
int dy[4] = { -1, 1, 0, 0 };

// ����, Ž�� ���� �˻�
bool IsPromising(int x, int y);

// ���� �˻�
bool IsRange(int x, int y);

// ���� ĭ�� ����� ��ĭ Ž��
void FindEmptySpace(int sx, int sy);

int main()
{
    string input;
    int cx, cy, nx, ny;
    bool IsSearch = false;
    vector<int> SearchEmptySpaceNumber;     // �̹� Ž���� ��ĭ�� ���ڵ�
    vector<pair<int, int>> Wall;            // ���� ��ġ��

    // board ���� �Է� �� ������ ��ġ�� vector�� ����
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;

        for (int j = 0; j < Row; j++)
        {
            Board[i][j] = input[j] - '0';
            CopyBoard[i][j] = Board[i][j];
            if (Board[i][j])
                Wall.push_back(make_pair(i, j));
        }
    }

    // ���� ����� ��ĭ�� ��ȣ�� ���δ�.
    for (int i = 0; i < Column; i++)
        for (int j = 0; j < Row; j++)
            if (!Board[i][j])
                FindEmptySpace(i, j);

    // ������ ��ġ���� �����¿츦 Ž���� ����� �� ĭ�� ������ ���Ѵ�.
    for (int i = 0; i < Wall.size(); i++)
    {
        cx = Wall[i].first;
        cy = Wall[i].second;

        for (int dir = 0; dir < 4; dir++)
        {
            nx = cx + dx[dir];
            ny = cy + dy[dir];

            // ���� �˻�
            if (!IsRange(nx, ny))
                continue;
            // �� �˻�
            if (CopyBoard[nx][ny] == 1)
                continue;
            // �ش� ��ĭ ��ȣ�� �̹� Ž���ߴ��� �˻�
            IsSearch = false;
            for (int j = 0; j < SearchEmptySpaceNumber.size(); j++)
            {
                if (SearchEmptySpaceNumber[j] == Board[nx][ny])
                {
                    IsSearch = true;
                    break;
                }
            }
            if (IsSearch)
                continue;

            // �˻縦 ��� ����ߴٸ�, �� ĭ�� ������ ���ϰ� Ž�� ����
            SearchEmptySpaceNumber.push_back(Board[nx][ny]);
            CopyBoard[cx][cy] = (CopyBoard[cx][cy] + EmptySpace[Board[nx][ny] - INIT]) % 10;
        }

        SearchEmptySpaceNumber.clear();
    }

    // ����� ���
    for (int i = 0; i < Column; i++)
    {
        for (int j = 0; j < Row; j++)
            cout << CopyBoard[i][j];
        cout << '\n';
    }

    return 0;
}

bool IsRange(int x, int y)
{
    if (x < 0 || x >= Column || y < 0 || y >= Row)
        return false;
    return true;
}

bool IsPromising(int x, int y)
{
    if (!IsRange(x, y))
        return false;
    if (Board[x][y])
        return false;

    return true;
}

void FindEmptySpace(int sx, int sy)
{
    queue<pair<int, int>> next;            // ������ Ž���� ĭ��
    int cx, cy, nx, ny;                    // ���� ��ġ, ���� ��ġ
    int cnt = 1;                             // �� ĭ�� ����

    // �������� Ž�� �����ϰ� queue�� push
    Board[sx][sy] = EmptySpaceCount;
    next.push(make_pair(sx, sy));

    // BFS ������� Ž��
    while (!next.empty())
    {
        cx = next.front().first;
        cy = next.front().second;
        next.pop();

        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (IsPromising(nx, ny))
            {
                Board[nx][ny] = EmptySpaceCount;
                next.push(make_pair(nx, ny));
                cnt++;
            }
        }
    }

    // �� ĭ�� ������ vector�� �ְ�, ��ĭ ��ȣ ����
    EmptySpace.push_back(cnt);
    EmptySpaceCount++;
}