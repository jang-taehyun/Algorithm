/*
problem : ���� �ٸ� 3���� ���ڰ� �־�����, ����(�� �� 2��(X, Y)�� ��� X+X, Y-X�� �ϴ� ��)���� ���� ���� ���ڰ� �ǰ� �Ϸ��� �Ѵ�.
          ���� �ٸ� 3���� ���ڸ� ���� ����� ����� ���ض�.
input : ���� �ٸ� 3���� ����
output : ���� �ٸ� 3���� ���ڸ� ���� ����� ���

idea
- ���� �ٸ� 3���� ���� ���� 3�� ����� �ƴ϶�� 0�� ���
- A <= B <= C ��� ����
- root�� �Էµ� ����, level�� ������ �� Ƚ��, node�� (A, B)�� ������ ��� �Ǵ� (A, C)�� ������ ���, (B, C)�� ������ ��츦 ��Ÿ���� tree�� �����.
- tree�� BFS ������� Ž���Ѵ�.
- �� node�� ���ڴ� ���� �Ŀ� ������������ �����Ѵ�.
- ����� ����� �̹� Ž���� node��� �� Ž������ �ʴ´�.
- ���� �� ���� 2���� ���� ���� ���ڶ�� Ž������ �ʴ´�.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXIMUM 501
using namespace std;

int TotalSum = 0;                               // ���� 3���� ��
bool Search[MAXIMUM][MAXIMUM];                // node Ž�� ����
                                              // 2���� ���ڿ� ������ �̿��ϸ� �ٸ� ���ڸ� ���� �� �ֱ� ������ 2���� ���ڸ� �̿�

bool BFS(int _n1, int _n2);

int main()
{
    // 3���� ���� �Է��ϰ�, ������ ���� �� ������������ ����
    int Input[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> Input[i];
        TotalSum += Input[i];
    }
    sort(Input, Input + 3);

    // BFS Ž�� ��� ���
    if (TotalSum % 3)
        cout << 0;
    else
        cout << BFS(Input[0], Input[1]);

    return 0;
}

bool BFS(int _n1, int _n2)
{
    queue<pair<int, int>> next;         // ������ Ž���� node���� ����
    int Current[3];                     // ���� node
    int Next[3];                        // ������ Ž���� node

    // root Ž�� ���θ� �����ϰ� queue�� push
    Search[_n1][_n2] = true;
    next.push(make_pair(_n1, _n2));

    // Ž��
    while (!next.empty())
    {
        // queue���� node�� �ϳ� ������ ����
        Current[0] = next.front().first;
        Current[1] = next.front().second;
        Current[2] = TotalSum - Current[0] - Current[1];
        next.pop();

        sort(Current, Current + 3);

        // ���� 3���� ���ڰ� ��� ���ٸ� true�� return
        if (Current[0] == Current[1] && Current[0] == Current[2])
            return true;

        // 2���� ���ڸ� ��� ����
        // (A, B)
        if (Current[0] != Current[1])
        {
            // ����
            Next[0] = Current[0] * 2;
            Next[1] = Current[1] - Current[0];
            Next[2] = Current[2];

            // ���� �� �˻�
            sort(Next, Next + 3);
            if (!Search[Next[0]][Next[1]])
            {
                Search[Next[0]][Next[1]] = true;
                next.push(make_pair(Next[0], Next[1]));
            }
        }
        // (A, C)
        if (Current[0] != Current[2])
        {
            // ����
            Next[0] = Current[0] * 2;
            Next[1] = Current[2] - Current[0];
            Next[2] = Current[1];

            // ���� �� �˻�
            sort(Next, Next + 3);
            if (!Search[Next[0]][Next[1]])
            {
                Search[Next[0]][Next[1]] = true;
                next.push(make_pair(Next[0], Next[1]));
            }
        }
        // (B, C)
        if (Current[1] != Current[2])
        {
            // ����
            Next[0] = Current[1] * 2;
            Next[1] = Current[2] - Current[1];
            Next[2] = Current[0];

            // ���� �� �˻�
            sort(Next, Next + 3);
            if (!Search[Next[0]][Next[1]])
            {
                Search[Next[0]][Next[1]] = true;
                next.push(make_pair(Next[0], Next[1]));
            }
        }
    }

    // ����� ã�� �������Ƿ� false�� ��ȯ
    return false;
}