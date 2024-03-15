/*
problem : 10*10 board���� 1~100���� ��ȣ�� �ް��� �ְ�, Ư�� ��ȣ�� ������ �� �ٸ� ��ȣ�� �̵��� �� ���� ��, 1�� ���� �����Ͽ� 100��° ĭ�� ������ ������ �ֻ����� ������ �ּ� Ƚ���� ���ض�.
input : Ư�� ��ȣ�� �������� �� �̵��ϴ� ��ȣ
output : 100��° ĭ�� ������ ������ ������ �ֻ����� �ּ� Ƚ��

idea
- level�� �ֻ����� ������ Ƚ��, node�� �ֻ����� ���� 1~6���� �� �����ϴ� ��ȣ�� ��Ÿ���� tree�� �����.
- tree�� BFS ������� Ž���Ѵ�.
- Ž���ϸ鼭 Ư�� ��ȣ�� �������� �� �̵��ϴ� ��ȣ�� �ִٸ�, �� ��ȣ�� �̵��Ѵ�.
- ������ Ž���� ĭ�̶�� �� Ž������ �ʴ´�.(Ž���� �ߺ��Ǳ� ����)
*/
#include <iostream>
#include <queue>
#define START 1
#define END 100
using namespace std;

int MoveNumber[END];                // index��° ĭ�� �������� �� �̵��ϴ� ĭ
                                    // 0�̶�� �̵����� �ʴ´�.
const int Length = END + 7;           // �湮 ������ ����
bool visited[Length];               // �� ĭ�� �湮 ����

int BFS()
{
    queue<int> next;                // �������� Ž���� node
    int QueueSize;                  // queue�� ũ��
    int CurrentNode, NextNode;      // ���� Ž���ϰ� �ִ� node, �������� Ž���� node
    int CurrentLevel = 0;             // ���� Ž���ϰ� �ִ� level

    // �������� �湮 ǥ���ϰ� queue�� �ִ´�.
    visited[START] = true;
    next.push(START);

    while (!next.empty())
    {
        // queue�� ũ�� ��ŭ �ݺ�
        QueueSize = next.size();
        for (int i = 0; i < QueueSize; i++)
        {
            // queue���� Ž���� node�� �ϳ� ������.
            CurrentNode = next.front();
            next.pop();

            // 100��° ĭ�� �����ϰų� 100�� �Ѵ´ٸ�, level(�ֻ����� ���� Ƚ��)�� return
            if (CurrentNode >= END)
                return CurrentLevel;

            // 6���� ��� �� ���� Ž������ �ʴ� ĭ�� queue�� �ִ´�.
            for (int j = 1; j <= 6; j++)
            {
                NextNode = CurrentNode + j;
                if (!visited[NextNode])
                {
                    visited[NextNode] = true;

                    // ���� Ư�� ĭ���� �̵��� �� �ִٸ�, Ư�� ĭ���� �̵�
                    if (MoveNumber[NextNode])
                    {
                        NextNode = MoveNumber[NextNode];
                        visited[NextNode] = true;
                    }

                    // queue�� �ִ´�.
                    next.push(NextNode);
                }
            }
        }

        // level ����
        CurrentLevel++;
    }
}

int main()
{
    int Special1, Special2;
    int Source, Destination;

    // �ٸ� ĭ���� �̵��� �� �ִ� Ư�� ĭ �Է�
    cin >> Special1 >> Special2;
    for (int i = 0; i < Special1 + Special2; i++)
    {
        cin >> Source >> Destination;
        MoveNumber[Source] = Destination;
    }

    // BFS�� ���� Ž���� �ֻ����� ������ �ּ� Ƚ���� ���Ѵ�.
    cout << BFS();

    return 0;
}