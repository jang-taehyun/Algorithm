/*
problem : n*m*h ũ�⸦ ������ 3���� �迭 S �ȿ� 0�� ĭ���� ��� 1�� �� ������ �ɸ��� �ð��� ���ض�.
input : n*m*h ũ�⸦ ������ 3���� �迭 S
output : �迭 S �ȿ� 0�� ĭ���� ��� 1�� �� ������ �ɸ��� �ð�

idea
- root�� �迭 S �ȿ��� 1�� ĭ��, level�� ������ �ð�, node�� �������� Ž���� ĭ���� ��Ÿ���� tree�� �����.
- tree�� BFS ������� Ž���Ѵ�.
- non-promising ����
  1) �̹� �湮�� ĭ�� ���
  2) �迭 S�� ������ �Ѿ ���
  3) 0�� �ƴ� ĭ�� ���� ���
- ��� Ž���� ���� ��, �迭 S�� �˻��� ���� 0�� ĭ�� �ִ��� Ȯ���Ѵ�.
  - ���� 0�� ĭ�� �ִٸ� -1�� ���
- �˰��� �ð� : 100*100*100*6 + 100*100*100 = 7*10^6
  �޸� : 100*100*100*2*5 = 10^7byte -> 10^4 kb -> 10 mb
*/
#include <iostream>
#include <queue>
using namespace std;

// node
typedef struct _node
{
    int c;
    int r;
    int h;

    void operator=(struct _node& ref)
    {
        c = ref.c;
        r = ref.r;
        h = ref.h;
    }
} Node;

int Column, Row, Height;            // 3���� �迭 S�� ����, ����, ����
int S[100][100][100];               // 3���� �迭 S
bool IsVisited[100][100][100];      // �� ĭ�� �湮 ����
queue<Node> Search;                 // ������ Ž���� ����
int Time = -1;                      // ���� �ð���

int dx[6] = { -1, 0, 1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

bool Promising(Node& check)
{
    if (check.c < 0 || check.c >= Column ||
        check.r < 0 || check.r >= Row ||
        check.h < 0 || check.h >= Height)
        return false;

    if (IsVisited[check.c][check.r][check.h])
        return false;

    if (S[check.c][check.r][check.h] == 1 || S[check.c][check.r][check.h] == -1)
        return false;

    return true;
}

void BFS()
{
    int NodeCount;                   // �� level�� �ִ� node�� ����
    Node cur, next;                  // ���� node, ���� node

    while (!Search.empty())
    {
        // level ����
        Time++;

        // �� level�� �ִ� node�� ������ŭ �ݺ�
        NodeCount = Search.size();
        while (NodeCount--)
        {
            cur = Search.front();
            Search.pop();

            for (int i = 0; i < 6; i++)
            {
                next.c = cur.c + dx[i];
                next.r = cur.r + dy[i];
                next.h = cur.h + dz[i];

                if (!Promising(next))
                    continue;

                IsVisited[next.c][next.r][next.h] = true;
                S[next.c][next.r][next.h] = 1;
                Search.push(next);
            }
        }
    }
}

int main()
{
    // 3���� �迭 S �Է�
    cin >> Row >> Column >> Height;
    for (int i = 0; i < Height; i++)
        for (int j = 0; j < Column; j++)
            for (int k = 0; k < Row; k++)
            {
                cin >> S[j][k][i];

                if (S[j][k][i] == 1)
                {
                    IsVisited[j][k][i] = true;
                    Search.push({ j, k, i });
                }
            }

    // tree�� BFS ������� Ž��
    BFS();

    // 3���� �迭 S�� Ž���� 0�� ĭ�� �����ϴ��� Ȯ���ϰ�,
    // ���� 0�� ĭ�� �����Ѵٸ� -1�� ���
    for (int i = 0; i < Height; i++)
        for (int j = 0; j < Column; j++)
            for (int k = 0; k < Row; k++)
            {
                if (!S[j][k][i])
                {
                    cout << -1;
                    return 0;
                }
            }
    cout << Time;

    return 0;
}