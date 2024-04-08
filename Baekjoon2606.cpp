/*
problem : graph �󿡼� 1�� node�������� �� �� �ִ� node���� ������ ���ض�.
input : graph
output : 1�� node�������� �� �� �ִ� node���� ����

idea
- 1�� node���� ������ BFS ������� Ž���Ѵ�.
- node�� �湮�� ������ ������� 1�� �����Ѵ�.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];            // graph
int NodeCount;                     // ��ü node�� ����
bool IsSearch[101];                  // �� node�� Ž�� ����
int res = 0;                         // �����

void BFS()
{
    queue<int> search;            // ������ Ž���� node��
    int cur, next;                // ���� node, ���� node

    // ������(1)�� queue�� �ְ� �湮 ó��
    search.push(1);
    IsSearch[1] = true;

    while (!search.empty())
    {
        cur = search.front();
        search.pop();

        // ����Ǿ� �ִ� node�� �� ���� �湮���� �ʴ� node�� queue�� �ִ´�.
        for (int i = 0; i < graph[cur].size(); i++)
        {
            next = graph[cur][i];

            if (IsSearch[next])
                continue;

            search.push(next);
            IsSearch[next] = true;
            res++;
        }
    }
}

int main()
{
    int n1, n2, EdgeCount;

    // graph �Է�
    cin >> NodeCount;
    cin >> EdgeCount;
    for (int i = 0; i < EdgeCount; i++)
    {
        cin >> n1 >> n2;

        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    // BFS Ž��
    BFS();

    // ����� ���
    cout << res;

    return 0;
}