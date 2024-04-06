/*
2
2+3, 3
2+3+5, 3+5, 5
2+3+5+7, 3+5+7, 5+7, 7
2+3+5+7+11, 3+5+7+11, 5+7+11, 7+11, 11
2+3+5+7+11+13, 3+5+7+11+13, 5+7+11+13, 7+11+13, 11+13, 13

problem : �ڿ��� n��, �� �� �̻� ���ӵǸ鼭 �ߺ����� �ʰ� �Ҽ��� ����Ͽ� ��Ÿ�� �� �ִ� ����� ���� ���ض�.
input : �ڿ��� n
output : �� �� �̻� ���ӵǸ鼭 �ߺ����� �ʰ� �Ҽ��� ����Ͽ� ��Ÿ�� �� �ִ� ����� ��

idea
- �ڿ��� n�� �Է¹ް�, �����佺�׳׽��� ü�� �̿��� �ڿ��� n�� �Ѿ�� ������ �Ҽ����� ��� ���Ѵ�.
- root�� 2, level�� ���� �Ҽ��� ����, node�� �Ҽ��� ���� ���� ���ڸ� ��Ÿ���� tree�� �����.
- tree�� ���� �Ҽ��� �ڿ��� n�� �Ѿ�� ������ BFS ������� Ž���Ѵ�.
- non-promising ���� : ���� ���� ���ڰ� �ڿ��� n�� �Ѿ ��
*/
#include <iostream>
#include <queue>
#define BOUND 4000001
using namespace std;

typedef unsigned int uint;

bool IsNotPrimary[BOUND];                   // �� ���ڰ� �Ҽ��� �ƴ��� ����
uint NumberOfCase[BOUND];                    // �� ���ڸ� ���� �� �ִ� ����� ��
uint Input;                                  // �Էµ� �ڿ��� n

// promising �Ǻ�
bool Promising(uint _node)
{
    if (_node > Input)
        return false;
    return true;
}

// �Ҽ� ã��
void FindPrimeNumber()
{
    // 1 ����
    IsNotPrimary[1] = true;

    // 2 ~ n������ ���� �� �Ҽ��� �ƴ� ���ڴ� ����
    for (uint i = 2; i * i <= Input; i++)
        if (!IsNotPrimary[i])
            for (uint j = i * i; j <= Input; j += i)
                IsNotPrimary[j] = true;
}

void BFS()
{
    queue<uint> search;                    // ������ Ž���� node���� ����
    uint cur, next;                        // ���� node, ���� node
    uint Adder = 3;                        // ���� ����
    uint QueueSize;                        // �� level�� �ִ� node�� ����(queue�� ũ��)

    // root�� queue�� �ְ�, root�� ����� ���� 1 ����
    search.push(2);
    NumberOfCase[2]++;

    // Ž��
    while (1)
    {
        // ���� ���ڸ� �Ҽ��� �����.
        while (Adder <= Input && IsNotPrimary[Adder])
            Adder += 2;

        // ���� ���ڰ� �ڿ��� n�� �Ѿ�� Ž�� ����
        if (Adder > Input)
            return;

        // queue�� ũ�⸸ŭ loop�� ���鼭 �Ҽ��� ���� �� promising �˻�
        QueueSize = search.size();
        while (QueueSize--)
        {
            cur = search.front();
            search.pop();

            next = cur + Adder;
            if (!Promising(next))
                continue;

            search.push(next);
            NumberOfCase[next]++;
        }
        search.push(Adder);
        NumberOfCase[Adder]++;

        // level ����
        Adder += 2;
    }
}

int main()
{
    // �ڿ��� n �Է�
    cin >> Input;

    // �ڿ��� n���� ���� �� �Ҽ��� �ƴ� ���ڴ� ����
    FindPrimeNumber();

    // tree�� BFS ������� Ž��
    BFS();

    // ����� ���
    cout << NumberOfCase[Input];

    return 0;
}