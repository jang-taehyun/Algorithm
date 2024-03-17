/*
problem : 0~9999�� ���� �� Ư�� ���ڿ��� D, S, L, R ������ �̿��� ��ǥ ���ڷ� ����� �ּ� ���� Ƚ���� ���ض�.
input : �ʱ� ����, ��ǥ ����
output : ��ǥ ���ڸ� ����� ���� D, S, L, R ������ �ּҷ� ����ϴ� Ƚ��

idea
- root�� �ʱ� ����, node�� D, S, L, R ������ �� ���� ���� ����� �ǹ��ϴ� tree�� �����.
- tree�� BFS ������� Ž���Ѵ�.
- tree�� Ž���� ��, �̹� Ž���� ���ڶ�� �� �̻� Ž������ �ʴ´�.
*/
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

bool Search[10000];                        // �ش� ���ڸ� Ž���ߴ��� ����

void BFS(int Start, int End)
{
    queue<pair<int, string>> next;           // ������ Ž���� node
    int CurrentNumber;                       // ���� ����
    string CurrentOperators;                 // ������� ������ �����
    int ComputeNumber;                       // ����� ����

    // �������� Ž�� �����ϰ�, queue�� �ִ´�.
    Search[Start] = true;
    next.push(make_pair(Start, ""));

    while (!next.empty())
    {
        CurrentNumber = next.front().first;
        CurrentOperators = next.front().second;
        next.pop();

        // ���� ��ǥ ���ڿ� �����ߴٸ�, ������� ������ ������� ����ϰ� Ž�� �ߴ�
        if (CurrentNumber == End)
        {
            cout << CurrentOperators << '\n';
            return;
        }

        // 4���� ���� ����
        // D
        ComputeNumber = (CurrentNumber * 2) % 10000;
        if (!Search[ComputeNumber])
        {
            Search[ComputeNumber] = true;
            next.push(make_pair(ComputeNumber, CurrentOperators + "D"));
        }

        // S
        ComputeNumber = CurrentNumber - 1;
        if (ComputeNumber < 0)
            ComputeNumber = 9999;
        if (!Search[ComputeNumber])
        {
            Search[ComputeNumber] = true;
            next.push(make_pair(ComputeNumber, CurrentOperators + "S"));
        }

        // L
        ComputeNumber = (CurrentNumber / 1000) + (CurrentNumber % 1000) * 10;
        if (!Search[ComputeNumber])
        {
            Search[ComputeNumber] = true;
            next.push(make_pair(ComputeNumber, CurrentOperators + "L"));
        }

        // R
        ComputeNumber = (CurrentNumber / 10) + (CurrentNumber % 10) * 1000;
        if (!Search[ComputeNumber])
        {
            Search[ComputeNumber] = true;
            next.push(make_pair(ComputeNumber, CurrentOperators + "R"));
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Start, End;
    int TestCase;
    cin >> TestCase;

    while (TestCase--)
    {
        cin >> Start >> End;
        BFS(Start, End);
        memset(Search, false, sizeof(Search));
    }

    return 0;
}