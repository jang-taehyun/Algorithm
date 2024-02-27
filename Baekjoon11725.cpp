/*
Problem : �� node�� parent�� ����ض�.
Input : Graph G
Output : �� node�� parent

idea
- �������� 1�� �����Ͽ� Graph�� BFS ������� Ž���Ѵ�.
- Ž���ϸ鼭 �� node�� parent�� �����Ѵ�.
- �ߺ� Ž���� ���� ���� �湮 ���θ� üũ�ϸ鼭 Ž���Ѵ�.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int NodeCount;                    // ��ü node�� ����
bool visited[100001];             // �� node�� �湮 ����
vector<int> Graph[100001];        // Graph G
int ParentNode[100001];           // �� node���� parent

void BFS()
{
    queue<int> next;               // ������ Ž���� node��
    int CurrentNode;               // ���� Ž���ϰ� �ִ� node

    // ���� node(1)�� queue�� �ְ� �湮�ߴٰ� üũ
    next.push(1);
    visited[1] = true;

    while (!next.empty())
    {
        // queue���� �ϳ��� ������.
        CurrentNode = next.front();
        next.pop();

        // ���� node�� ����� node �� �湮���� �ʴ� node�� Ž���Ѵ�.
        for (int i = 0; i < Graph[CurrentNode].size(); i++)
        {
            if (!visited[Graph[CurrentNode][i]])
            {
                // �湮 ���� ǥ��, parent�� ���� node�� ����
                visited[Graph[CurrentNode][i]] = true;
                ParentNode[Graph[CurrentNode][i]] = CurrentNode;

                // queue�� ������ Ž���� node�� push
                next.push(Graph[CurrentNode][i]);
            }
        }
    }
}

int main()
{
    int tmp1, tmp2;

    // ��ü node�� ������ Graph�� �Է�
    cin >> NodeCount;
    for (int i = 0; i < NodeCount - 1; i++)
    {
        cin >> tmp1 >> tmp2;

        Graph[tmp1].push_back(tmp2);
        Graph[tmp2].push_back(tmp1);
    }

    // ������ 1���� BFS ������� Ž���� �� node�� parent�� ã��
    BFS();

    // 2�� node���� �����Ͽ�, �� node���� parent�� ���
    for (int i = 2; i <= NodeCount; i++)
        cout << ParentNode[i] << '\n';

    return 0;
}