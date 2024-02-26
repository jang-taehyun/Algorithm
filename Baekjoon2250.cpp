/*
Problem : binary tree에서 최대 너비를 가진 level과 그 너비를 구해라.
Input : Node의 개수, binary tree
Output : binary tree에서 최대 너비를 가진 level, 그 level의 최대 너비

Idea
- binary tree를 inorder 순으로 순회하고 DFS 방식으로 탐색한다.
- Root를 방문했을 때, 현재 level에서 가장 먼저 탐색한 Inorder 순번과 가장 나중에 탐색한 Inorder 순번을 update한다.
- 트리의 최대 높이를 비교하면서 update한다.
- 1번 Node는 Root가 아닐 수도 있기 때문에 binary tree를 입력하면서 입력 횟수가 가장 적은 Node를 Root로 한다.
- 탐색 후, 각 level에서 가장 먼저 탐색한 순서와 가장 나중에 탐색한 순서를 빼서 각 level에서 나오는 최대 너비를 구하고, 결과값을 update한다
*/
#include <iostream>
#include <algorithm>
#define MAX_LEVEL_AND_NODE_COUNT 10001
#define MAX_VALUE 99999999
using namespace std;

int NodeCount = 0;                                                    // 전체 node의 개수
int InorderSearchSequence = 1;                                        // Inoder(중위 순회) 탐색 순서
int EachLevelFirstSearchCount[MAX_LEVEL_AND_NODE_COUNT];            // 각 level을 먼저 탐색하는 탐색 순서
int EahcLevelLastSearchCount[MAX_LEVEL_AND_NODE_COUNT];             // 각 level을 가장 나중에 탐색하는 탐색 순서
pair<int, int> tree[MAX_LEVEL_AND_NODE_COUNT];                      // binary tree
int InputCountEachNode[MAX_LEVEL_AND_NODE_COUNT];                   // 각 node들이 입력된 횟수
int TreeLevel = 0;

void InorderDFS(int CurrentNode, int CurrentLevel)
{
    // Left subtree search
    if (tree[CurrentNode].first != -1)
        InorderDFS(tree[CurrentNode].first, CurrentLevel + 1);

    // Root search
    // 현재 level에서 가장 먼저 탐색한 순서와 가장 나중에 탐색한 순서를 update한다.
    EachLevelFirstSearchCount[CurrentLevel] = min(EachLevelFirstSearchCount[CurrentLevel], InorderSearchSequence);
    EahcLevelLastSearchCount[CurrentLevel] = max(EahcLevelLastSearchCount[CurrentLevel], InorderSearchSequence);

    // Inorder 탐색 순서를 1 증가
    InorderSearchSequence++;

    // tree의 level update
    TreeLevel = max(TreeLevel, CurrentLevel);

    // Right subtree search
    if (tree[CurrentNode].second != -1)
        InorderDFS(tree[CurrentNode].second, CurrentLevel + 1);
}

int main()
{
    int Root = 0, Left = 0, Right = 0, ResultLevel = 0, ResultWidth = 0, tmp = 0;

    // 각 level을 가장 먼저 탐색하는 탐색 순서를 MAX_VALUE로 초기화
    for (int i = 0; i < MAX_LEVEL_AND_NODE_COUNT; i++)
        EachLevelFirstSearchCount[i] = MAX_VALUE;

    // 전체 Node의 개수 및 binary tree 입력
    // 이 때, Root node를 찾기 위해 각 Node들이 입력된 횟수를 센다.
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

    // 입력된 Node들 중 가장 적게 입력된 Node를 Root로 삼는다.
    Root = 1;
    for (int i = 1; i <= NodeCount; i++)
        if (InputCountEachNode[Root] > InputCountEachNode[i])
            Root = i;

    // DFS 방식으로 tree를 Inorder 순회
    InorderDFS(Root, 1);

    // 각 level에서 가장 먼저 탐색한 순서와 가장 나중에 탐색한 순서를 빼서,
    // 각 level에서 나오는 최대 너비를 구하고, 결과값을 update한다.
    for (int i = 1; i <= TreeLevel; i++)
    {
        tmp = EahcLevelLastSearchCount[i] - EachLevelFirstSearchCount[i] + 1;

        if (tmp > ResultWidth)
        {
            ResultLevel = i;
            ResultWidth = tmp;
        }
    }

    // 결과값 출력
    cout << ResultLevel << ' ' << ResultWidth;

    return 0;
}
