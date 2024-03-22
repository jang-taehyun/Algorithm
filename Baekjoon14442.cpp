/*
problem : n*m board �ȿ��� (1, 1)���� ������ �ִ� k���� ���� �μ��� (n, m)�� �����ϴ� �ִ� �Ÿ��� ���ض�.
input : n*m board, �μ� �� �ִ� ���� ���� k
output : (1, 1)���� ������ �ִ� k���� ���� �μ��� (n, m)�� �����ϴ� �ִ� �Ÿ�

idea
- root�� (1, 1), level�� �̵��� ĭ�� ����, node�� �����¿�� ������ ���� ��ǥ�� ���� �� �� �μ����� ��Ÿ���� ���ڷ� ������ tree�� �����.
- tree�� BFS ������� Ž���Ѵ�.
- �����¿�� �����̰� �μ� ���� ������ ���� node�� �� �̻� Ž������ �ʴ´�.
*/
#include <iostream>
#include <queue>
#include <string>
#define BOUND 1000
#define BREAK_WALL_MAX_COUNT 10
using namespace std;

// node
typedef struct _node
{
    int x;
    int y;
    int BreakWall;
} Node;

int Column, Row;                                        // board�� column, row
int BreakWallCount;                                     // �μ� �� �ִ� ���� ����
int Board[BOUND][BOUND];                                // n*m board
bool Search[BOUND][BOUND][BREAK_WALL_MAX_COUNT];        // node�� Ž�� ����
int dx[4] = { 0, 0, 1, -1 };                              // �̵� ���
int dy[4] = { -1, 1, 0, 0 };

// ����, Ž�� ���� �˻�(promising �˻�)
bool IsPromising(int x, int y, int BreaWallCount);

// node Ž��
int BFS();

int main()
{
    string input;

    // n*m board�� ���� �Է�
    cin >> Column >> Row >> BreakWallCount;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;
        for (int j = 0; j < Row; j++)
            Board[i][j] = input[j] - '0';
    }

    // tree�� BFS ������� Ž���� �ִ� �Ÿ��� ���Ѵ�.
    cout << BFS();

    return 0;
}

bool IsPromising(Node& ref)
{
    // ���� �˻�
    if (ref.x < 0 || ref.x >= Column || ref.y < 0 || ref.y >= Row)
        return false;

    // Ž�� ���� �˻�
    if (Search[ref.x][ref.y][ref.BreakWall])
        return false;

    return true;
}

int BFS()
{
    queue<Node> next;                // ������ Ž���� node
    int MoveCount = 1;                 // ĭ�� �̵��� Ƚ��(level)
    int QueueSize = 0;                 // queue�� ũ��
    Node CurrentNode, NextNode;      // ���� node, ���� node

    // �������� queue�� �ְ� Ž�� ����
    Search[0][0][0] = true;
    next.push({ 0, 0, 0 });

    // Ž��
    while (!next.empty())
    {
        // �� level�� Ž���� queue�� ũ�⸸ŭ �ݺ�
        QueueSize = next.size();
        while (QueueSize--)
        {
            CurrentNode.x = next.front().x;
            CurrentNode.y = next.front().y;
            CurrentNode.BreakWall = next.front().BreakWall;
            next.pop();

            // �������� �����ߴٸ� level�� return
            if (CurrentNode.x == Column - 1 && CurrentNode.y == Row - 1)
                return MoveCount;

            // 4���� �̵� ���� Ž��
            for (int i = 0; i < 4; i++)
            {
                NextNode.x = CurrentNode.x + dx[i];
                NextNode.y = CurrentNode.y + dy[i];
                NextNode.BreakWall = CurrentNode.BreakWall;

                // ����, Ž�� ���� �˻�(promising �˻�)
                if (!IsPromising(NextNode))
                    continue;

                // �� ������ ���
                if (!Board[NextNode.x][NextNode.y])
                {
                    Search[NextNode.x][NextNode.y][NextNode.BreakWall] = true;
                    next.push(NextNode);
                }
                // ���̸鼭 ���� �μ� �� �ִ� Ƚ���� ���� ���
                if (Board[NextNode.x][NextNode.y] && NextNode.BreakWall < BreakWallCount)
                {
                    Search[NextNode.x][NextNode.y][NextNode.BreakWall] = true;
                    NextNode.BreakWall++;
                    Search[NextNode.x][NextNode.y][NextNode.BreakWall] = true;
                    next.push(NextNode);
                }
            }
        }

        // ĭ�� �̵��� Ƚ��(level) ����
        MoveCount++;
    }

    // ����� ã�� �������Ƿ� -1�� return
    return -1;
}