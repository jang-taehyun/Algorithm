/*
problem : n*m board���� �� ĭ(0�� ĭ)�� ��(1�� ĭ)�� �ִ�. (1, 1)���� �����Ͽ� (n, m)���� ���� �ִ� �Ÿ��� ���ϴµ�,
          �� �� �̵��� ������ ���� ���� �ٲ��. ������ �ִ� ��쿡�� ���� ���� �ٲ��, �̷� ��쿡�� �湮�� ĭ�� ������ �ϳ� �þ�� ������ �����Ѵ�.
          ���� ������ �μ� �� �ְ�, �ִ� k������ �μ� �� �ִ�.
          �̷��� ������ ����� (1, 1)���� �����Ͽ� (n, m)���� ���� �ִ� �Ÿ��� ���ض�.
input : n*m board, �μ� �� �ִ� ���� ���� k
output : ������ ����� (1, 1)���� �����Ͽ� (n, m)���� ���� �ִ� �Ÿ�

idea
- root�� (1, 1), level�� �̵��� ĭ�� ����, node�� �̵��� ���� ��ġ�� �㳷�� ����, �μ� ���� ������ ��Ÿ���� tree�� �����.
- tree�� BFS ������� Ž���Ѵ�.
- �̹� Ž���� node�� �ٽ� Ž������ �ʴ´�.
- promising ���� : ������ �Ѿ�� ���� ��, ���� Ž������ ���� node�� ��
*/
#include <iostream>
#include <queue>
#include <string>
#define BOUND 1000
#define BREAK_WALL_MAX_COUNT 11
#define STATE 2
using namespace std;

typedef struct _node
{
    int x;            // ��ǥ
    int y;
    int BreakWall;    // �μ� ���� ����
    int State;        // 0 : ��, 1 : ��
} Node;

int Column, Row;                                        // board�� column, row
int Board[BOUND][BOUND];                                // board�� ����
bool Search[BOUND][BOUND][BREAK_WALL_MAX_COUNT][STATE]; // node�� Ž�� ����
                                                        // 0 : ��, 1 : ��
int BreakWallCount;                                     // �μ� �� �ִ� ���� ����
int dx[4] = { 0, 0, 1, -1 };                              // �̵� ����
int dy[4] = { -1, 1, 0, 0 };

// promising �˻�
bool Promising(const Node& Check);

// node Ž��
int BFS();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;

    // n*m board�� ������ �μ� �� �ִ� ���� ���� �Է�
    cin >> Column >> Row >> BreakWallCount;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;
        for (int j = 0; j < Row; j++)
            Board[i][j] = input[j] - '0';
    }

    // BFS ������� tree�� Ž���ϰ� ������� ���
    cout << BFS();

    return 0;
}

bool Promising(const Node& Check)
{
    if (Check.x < 0 || Check.x >= Column || Check.y < 0 || Check.y >= Row)
        return false;
    if (Search[Check.x][Check.y][Check.BreakWall][Check.State])
        return false;
    return true;
}

int BFS()
{
    queue<Node> next;            // ������ Ž���� node���� ����
    Node CurrentNode, NextNode;  // ���� node, ���� node
    int MoveCount = 1;             // �̵��� ĭ�� ����(level)
    int QueueSize;               // queue�� ũ��(�� level�� node ����)

    // ������(1, 1)�� queue�� �ְ� Ž�� ����
    Search[0][0][0][0] = true;
    next.push({ 0, 0, 0, 0 });

    // Ž��
    while (!next.empty())
    {
        // queue�� ũ�⸸ŭ �ݺ�
        QueueSize = next.size();
        while (QueueSize--)
        {
            CurrentNode.x = next.front().x;
            CurrentNode.y = next.front().y;
            CurrentNode.BreakWall = next.front().BreakWall;
            CurrentNode.State = next.front().State;
            next.pop();

            // �������� �����ߴٸ� level�� return
            if (CurrentNode.x == Column - 1 && CurrentNode.y == Row - 1)
                return MoveCount;

            // ������ Ž���� ĭ���� queue�� �ִ´�.
            for (int i = 0; i < 4; i++)
            {
                NextNode.x = CurrentNode.x + dx[i];
                NextNode.y = CurrentNode.y + dy[i];
                NextNode.BreakWall = CurrentNode.BreakWall;
                NextNode.State = !(CurrentNode.State);

                // promising �˻�
                if (!Promising(NextNode))
                    continue;

                // �� ĭ�� ���
                if (!Board[NextNode.x][NextNode.y])
                {
                    Search[NextNode.x][NextNode.y][NextNode.BreakWall][NextNode.State] = true;
                    next.push(NextNode);
                }

                // ���̸鼭 �μ� �� �ִ� ���� ������ �����ִ� ���
                if (Board[NextNode.x][NextNode.y] && NextNode.BreakWall < BreakWallCount)
                {
                    // ���� ���� ����
                    if (!CurrentNode.State && !Search[NextNode.x][NextNode.y][NextNode.BreakWall + 1][NextNode.State])
                    {
                        NextNode.BreakWall++;
                        Search[NextNode.x][NextNode.y][NextNode.BreakWall][NextNode.State] = true;
                        next.push(NextNode);
                    }
                    // ���� ���� ����
                    else if (CurrentNode.State && !Search[CurrentNode.x][CurrentNode.y][CurrentNode.BreakWall][!CurrentNode.State])
                    {
                        Search[CurrentNode.x][CurrentNode.y][CurrentNode.BreakWall][!CurrentNode.State] = true;
                        next.push({ CurrentNode.x, CurrentNode.y, CurrentNode.BreakWall, !CurrentNode.State });
                    }
                }
            }
        }

        // level ����
        MoveCount++;
    }

    // �������� �����ϴ� ���� �Ұ����ϹǷ� -1�� return
    return -1;
}