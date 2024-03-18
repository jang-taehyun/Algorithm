/*
Problem : n*m board�� 2�� ĭ�� �ְ� 2�� ĭ�� �����¿�� �� ĭ(0�� ĭ)�� ������Ų��.
          �̶�, ��(1�� ĭ)�� 3�� �߰��� ��, ������ ���� �� ĭ(0�� ĭ)�� �ִ� ������ ���ض�.
input : n*m board�� ����
output : �� ĭ�� �ִ� ����

idea
- DFS�� ���� �� ĭ(0�� ĭ) �� ��(1�� ĭ)�� ���� ���� 3�� ���Ѵ�.
- ����, BFS�� ���� 2�� ĭ�� ������Ų��.
- �� ĭ�� ������ ���Ѵ�.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define BOARD_MAX_LENGTH 8
#define CHOOSE_COUNT 3
using namespace std;

int Column, Row;                                      // board�� column, row�� ����
int Board[BOARD_MAX_LENGTH][BOARD_MAX_LENGTH];        // board�� ����
int CopyBoard[BOARD_MAX_LENGTH][BOARD_MAX_LENGTH];    // ������ board
vector<pair<int, int>> EmptySpace;                    // �� ĭ���� ����
int MaximumEmptySpace = 0;                              // ���� ���� ��ĭ�� �ִ� ����
int dx[4] = { 0, 0, -1, 1 };                            // 2�� ĭ�� �̵� ���
int dy[4] = { -1, 1, 0, 0 };

// ���� ���� ���� ���Ѵ�.
void DFS(int start, int cnt);

// 2�� ĭ�� ������Ų��.
void BFS();

// ���� board�� ���¸� ����
void CopyBoardFunc();

// ���� ���� �ִ��� �˻�
bool IsRange(int _x, int _y);

int main()
{
    // m*n board�� ���� �Է�
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
    {
        for (int j = 0; j < Row; j++)
        {
            cin >> Board[i][j];

            // ���� �� ĭ�̶��, vector�� �ִ´�.
            if (!Board[i][j])
                EmptySpace.push_back(make_pair(i, j));
        }
    }

    // �� ĭ(0�� ĭ)�� ��(1�� ĭ)�� 3�� ����, 2�� ĭ�� �������� �����ִ� �� ĭ�� �ִ� ������ ���Ѵ�.
    DFS(0, 0);

    // ����� ���
    cout << MaximumEmptySpace;

    return 0;
}

void DFS(int start, int cnt)
{
    // �� ĭ �� ��(1�� ĭ)�� ���� ĭ�� ��� ����ٸ�, ���� ���� �� ĭ�� ������ ���Ѵ�.
    if (cnt >= CHOOSE_COUNT)
    {
        // board�� �����ϰ�, ����� board�� BFS Ž���� �Ѵ�.
        CopyBoardFunc();
        BFS();

        return;
    }

    // �� ĭ �� ���� ���� ĭ�� ����.
    int cx, cy;
    for (int i = start; i < EmptySpace.size(); i++)
    {
        cx = EmptySpace[i].first;
        cy = EmptySpace[i].second;

        if (!Board[cx][cy])
        {
            Board[cx][cy] = 1;
            DFS(i, cnt + 1);
            Board[cx][cy] = 0;
        }
    }
}

void BFS()
{
    queue<pair<int, int>> next;            // 2�� ������ ĭ
    int Empty = 0;                           // �� ĭ�� ����
    int cx, cy, nx, ny;                    // ���� Ž���ϰ� �ִ� ĭ, ������ Ž���� ĭ

    // 2�� ������ ĭ�� ��� queue�� �ְ�, ���� �� ĭ(0�� ĭ)�� ������ ���Ѵ�.
    for (int i = 0; i < Column; i++)
    {
        for (int j = 0; j < Row; j++)
        {
            if (CopyBoard[i][j] == 2)
                next.push(make_pair(i, j));
            if (!CopyBoard[i][j])
                Empty++;
        }
    }

    // 2�� ������ ĭ�� �������� �� ĭ(0�� ĭ)�� ������Ų��.
    while (!next.empty())
    {
        cx = next.front().first;
        cy = next.front().second;
        next.pop();

        // �̵� ����(4����)�� ���� ����
        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            // ����, �� ĭ���� �˻�
            if (!IsRange(nx, ny))
                continue;
            if (CopyBoard[nx][ny])
                continue;

            // ������Ű��, queue�� push
            CopyBoard[nx][ny] = 2;
            next.push(make_pair(nx, ny));
            Empty--;
        }
    }

    // ���� �� ĭ�� ������ ���� ������� update
    MaximumEmptySpace = max(MaximumEmptySpace, Empty);
}

void CopyBoardFunc()
{
    for (int i = 0; i < Column; i++)
    {
        for (int j = 0; j < Row; j++)
        {
            CopyBoard[i][j] = Board[i][j];
        }
    }
}

bool IsRange(int _x, int _y)
{
    if (_x < 0 || _x >= Column || _y < 0 || _y >= Row)
        return false;
    return true;
}