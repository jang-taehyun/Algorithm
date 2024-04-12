/*
problem : �迭 S �ȿ� �� index�� ������ ���ڰ� ������ ��, ���õ��� ���� �׷쿡 ������ �ʴ� ������ ������ ���ض�.
input : �迭 S
output : ���õ��� ���� �׷쿡 ������ �ʴ� ������ ����

idea
- root�� index, level�� Ž���� Ƚ��, node�� ������ Ž���� index�� �ǹ��ϴ� tree�� �����.
- tree�� DFS ������� Ž���Ѵ�.
- non-promising ����
  - �̹� Ž���� �Ϸ��� ��湮�� ���� ���� node�� Ž���Ϸ��� ���
  - �̹� Ž���� index�� �ٽ� Ž���� ��, ��湮 ���ΰ� �����ִ� ��� -> Cycle ����
- �� index���� tree�� DFS ������� Ž���ϸ鼭, cycle�� �߰��ϸ� ��ü �������� cycle�� �ִ� ����� ������ ����.

���� �ڷ� : https://jaimemin.tistory.com/674
*/
#include <iostream>
#include <cstring>
using namespace std;

int Tree[100000];                    // tree
bool IsSearch[100000];               // �ش� node �湮 ����
bool IsSearchDone[100000];           // �ش� node�� �� Ž������ ���� ����
int res = 100000;

void DFS(int cur)
{
    // ���� node�� �̹� Ž���ߴ��� Ȯ��
    if (!IsSearch[cur])
    {
        IsSearch[cur] = true;
        DFS(Tree[cur]);
    }
    // ���� node�� ��湮 ������ �ٽ� �湮�� ������ �ִٸ�,
    // ���� node�� ���� ������ tree�� �������� Ž���� cycle�� �ִ´�.
    else if (IsSearch[cur] && !IsSearchDone[cur])
    {
        // index�� ���� node�� �� ������ �׷����� ����
        int idx = cur;
        int minus = 0;
        do
        {
            IsSearchDone[idx] = true;
            idx = Tree[idx];
            minus++;
        } while (idx != cur);

        // ��ü �������� �׷쿡 ���� �ο� ����
        res -= minus;

        // Ž�� ����
        return;
    }

    // ��湮 ���� ����
    IsSearchDone[cur] = true;
}

int main()
{
    // test Ƚ�� �Է�
    int test, len, tmp;
    cin >> test;

    while (test--)
    {
        // �ʱ�ȭ
        memset(IsSearchDone, 0, sizeof(IsSearchDone));
        memset(IsSearch, 0, sizeof(IsSearch));
        memset(Tree, 0, sizeof(Tree));

        // �迭 S �Է�
        cin >> len;
        for (int i = 0; i < len; i++)
        {
            cin >> tmp;
            Tree[i] = tmp - 1;
        }

        // BFS Ž��
        res = len;
        for (int i = 0; i < len; i++)
            DFS(i);

        // ����� ���
        cout << res << '\n';
    }

    return 0;
}