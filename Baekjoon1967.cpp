/*
Problem : tree�� ����(Ʈ������ weight���� ���� ���� ū �� node ������ �Ÿ�)�� ���ض�
Input : tree
Output : tree�� ����

Idea
- ������ node(1�� node)���� DFS ����� �̿��� weight���� ���� ���� �� node�� ã�´�.
- ã�� node���� DFS ����� �̿��� tree�� ������ ���Ѵ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int NodeCount;                                   // node�� ����
bool visited[10001];                             // �� node�� �湮 ����
vector<pair<int, int>> Tree[10001];              // tree
int MaximumWeightSumNode, MaximumWeightSum = 0;    // ������ node���� weight���� ���� ���� �� node, tree�� ����

void DFS(int CurrentNode, int CurrentWeightSum)
{
    // ���� �̹� �湮�� node��� Ž������ �ʴ´�.
    if (visited[CurrentNode])
        return;

    // ���� �湮�ϰ� �ִ� node�� �湮 ó��
    visited[CurrentNode] = true;

    // ������� Ž���� ����� weight���� ���� ������ tree�� �������� ũ��,
    // MaximumWeightSumNode�� MaximumWeightSum�� update
    if (MaximumWeightSum < CurrentWeightSum)
    {
        MaximumWeightSumNode = CurrentNode;
        MaximumWeightSum = CurrentWeightSum;
    }

    // ����� node���� �湮
    int NextNode, NextWeight;
    for (int i = 0; i < Tree[CurrentNode].size(); i++)
    {
        NextNode = Tree[CurrentNode][i].first;
        NextWeight = Tree[CurrentNode][i].second;

        DFS(NextNode, CurrentWeightSum + NextWeight);
    }
}

int main()
{
    int Parent, Child, Weight;

    // node�� ������ tree �Է�
    cin >> NodeCount;
    for (int i = 0; i < NodeCount - 1; i++)
    {
        cin >> Parent >> Child >> Weight;

        Tree[Parent].push_back(make_pair(Child, Weight));
        Tree[Child].push_back(make_pair(Parent, Weight));
    }

    // ������ node(1��° node)���� �����ϴ� tree�� ������ ���ϰ�, ���� node�� ã��
    DFS(1, 0);

    // �湮 ���θ� �ʱ�ȭ�ϰ� ã�� ���� node���� ���� tree�� ������ ���Ѵ�.
    memset(visited, false, sizeof(visited));
    DFS(MaximumWeightSumNode, 0);

    // ����� ���
    cout << MaximumWeightSum;

    return 0;
}