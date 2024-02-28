/*
Problem : tree���� ���� �� ����ġ�� ���� ���ض�.
Input : tree �� �� edge�� weight
Output : ���� �� ����ġ�� ��

Idea
- vector�� pair�� �̿��� tree�� edge�� weight�� �Է¹޴´�.
- ������ node(1�� node)���� ���� �� weight���� ���� ���� node�� weight���� ���� ���Ѵ�.
- ������ node���� ���� �� weight���� ���� ���� node�� ã�� weight���� ���� ���Ѵ�.

* ���� �ڷ� : https://blog.myungwoo.kr/112
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int NodeCount;                            // tree�� ��ü node�� ����
vector<pair<int, int>> Tree[100001];      // tree
                                          // first : ����� node
                                          // second : edge�� weight
bool visited[100001];                     // �� node�� �湮 ����
int MaxWeightSumNode, MaxWeightSum = 0;     // ���� �� weight���� ���� ���� node, weight���� ��

void DFS(int CurrentNode, int CurrentLength)
{
    // �̹� �湮�ߴٸ� Ž������ ����
    if (visited[CurrentNode])
        return;

    // ���� node�� �湮 ó���ϰ�,
    // ���� �� weigth���� ���� ���� node���� �Ǵ��Ͽ� update
    visited[CurrentNode] = true;
    if (MaxWeightSum < CurrentLength)
    {
        MaxWeightSumNode = CurrentNode;
        MaxWeightSum = CurrentLength;
    }

    int NextNode, NextNodeLength;        // ���� node�� ����� node�� edge�� ����ġ
    int tmp;

    // ���� node�� ����� ��� node�� ����
    for (int i = 0; i < Tree[CurrentNode].size(); i++)
    {
        NextNode = Tree[CurrentNode][i].first;
        NextNodeLength = Tree[CurrentNode][i].second;

        DFS(NextNode, CurrentLength + NextNodeLength);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int InputNodeNumber, InputConnectedNodeNumber, InputWeight;
    int Result = 0, tmp = 0;

    // ��ü node�� ���� �Է� �� tree�� edge�� weight ���� �Է�
    cin >> NodeCount;
    for (int i = 0; i < NodeCount; i++)
    {
        cin >> InputNodeNumber;

        while (1)
        {
            cin >> InputConnectedNodeNumber;

            // ���� -1�� �ԷµǸ� while�� ����
            if (-1 == InputConnectedNodeNumber)
                break;

            cin >> InputWeight;

            Tree[InputNodeNumber].push_back(make_pair(InputConnectedNodeNumber, InputWeight));
        }
    }

    // ������ node(1�� node)���� ���� �� weight���� ���� ���� node�� weight���� ���� ���Ѵ�.
    DFS(1, 0);

    // �湮 ���θ� �ʱ�ȭ�ϰ�, ������ node���� ���� �� weight���� ���� ���� node�� weight���� ���� ���Ѵ�.
    memset(visited, false, sizeof(visited));
    DFS(MaxWeightSumNode, 0);

    // ����� ���
    cout << MaxWeightSum;

    return 0;
}