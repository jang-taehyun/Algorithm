/*
Problem : binary tree���� �ִ� �ʺ� ���� level�� �� �ʺ� ���ض�.
Input : Node�� ����, binary tree
Output : binary tree���� �ִ� �ʺ� ���� level, �� level�� �ִ� �ʺ�

Idea
- binary tree�� inorder ������ ��ȸ�ϰ� DFS ������� Ž���Ѵ�.
- Root�� �湮���� ��, ���� level���� ���� ���� Ž���� Inorder ������ ���� ���߿� Ž���� Inorder ������ update�Ѵ�.
- Ʈ���� �ִ� ���̸� ���ϸ鼭 update�Ѵ�.
- 1�� Node�� Root�� �ƴ� ���� �ֱ� ������ binary tree�� �Է��ϸ鼭 �Է� Ƚ���� ���� ���� Node�� Root�� �Ѵ�.
- Ž�� ��, �� level���� ���� ���� Ž���� ������ ���� ���߿� Ž���� ������ ���� �� level���� ������ �ִ� �ʺ� ���ϰ�, ������� update�Ѵ�
*/
#include <iostream>
#include <algorithm>
#define MAX_LEVEL_AND_NODE_COUNT 10001
#define MAX_VALUE 99999999
using namespace std;

int NodeCount = 0;                                                    // ��ü node�� ����
int InorderSearchSequence = 1;                                        // Inoder(���� ��ȸ) Ž�� ����
int EachLevelFirstSearchCount[MAX_LEVEL_AND_NODE_COUNT];            // �� level�� ���� Ž���ϴ� Ž�� ����
int EahcLevelLastSearchCount[MAX_LEVEL_AND_NODE_COUNT];             // �� level�� ���� ���߿� Ž���ϴ� Ž�� ����
pair<int, int> tree[MAX_LEVEL_AND_NODE_COUNT];                      // binary tree
int InputCountEachNode[MAX_LEVEL_AND_NODE_COUNT];                   // �� node���� �Էµ� Ƚ��
int TreeLevel = 0;

void InorderDFS(int CurrentNode, int CurrentLevel)
{
    // Left subtree search
    if (tree[CurrentNode].first != -1)
        InorderDFS(tree[CurrentNode].first, CurrentLevel + 1);

    // Root search
    // ���� level���� ���� ���� Ž���� ������ ���� ���߿� Ž���� ������ update�Ѵ�.
    EachLevelFirstSearchCount[CurrentLevel] = min(EachLevelFirstSearchCount[CurrentLevel], InorderSearchSequence);
    EahcLevelLastSearchCount[CurrentLevel] = max(EahcLevelLastSearchCount[CurrentLevel], InorderSearchSequence);

    // Inorder Ž�� ������ 1 ����
    InorderSearchSequence++;

    // tree�� level update
    TreeLevel = max(TreeLevel, CurrentLevel);

    // Right subtree search
    if (tree[CurrentNode].second != -1)
        InorderDFS(tree[CurrentNode].second, CurrentLevel + 1);
}

int main()
{
    int Root = 0, Left = 0, Right = 0, ResultLevel = 0, ResultWidth = 0, tmp = 0;

    // �� level�� ���� ���� Ž���ϴ� Ž�� ������ MAX_VALUE�� �ʱ�ȭ
    for (int i = 0; i < MAX_LEVEL_AND_NODE_COUNT; i++)
        EachLevelFirstSearchCount[i] = MAX_VALUE;

    // ��ü Node�� ���� �� binary tree �Է�
    // �� ��, Root node�� ã�� ���� �� Node���� �Էµ� Ƚ���� ����.
    cin >> NodeCount;
    for (int i = 0; i < NodeCount; i++)
    {
        cin >> Root >> Left >> Right;

        InputCountEachNode[Root]++;

        if (Left != -1)
            InputCountEachNode[Left]++;
        tree[Root].first = Left;

        if (Right != -1)
            InputCountEachNode[Right]++;
        tree[Root].second = Right;
    }

    // �Էµ� Node�� �� ���� ���� �Էµ� Node�� Root�� ��´�.
    Root = 1;
    for (int i = 1; i <= NodeCount; i++)
        if (InputCountEachNode[Root] > InputCountEachNode[i])
            Root = i;

    // DFS ������� tree�� Inorder ��ȸ
    InorderDFS(Root, 1);

    // �� level���� ���� ���� Ž���� ������ ���� ���߿� Ž���� ������ ����,
    // �� level���� ������ �ִ� �ʺ� ���ϰ�, ������� update�Ѵ�.
    for (int i = 1; i <= TreeLevel; i++)
    {
        tmp = EahcLevelLastSearchCount[i] - EachLevelFirstSearchCount[i] + 1;

        if (tmp > ResultWidth)
        {
            ResultLevel = i;
            ResultWidth = tmp;
        }
    }

    // ����� ���
    cout << ResultLevel << ' ' << ResultWidth;

    return 0;
}
