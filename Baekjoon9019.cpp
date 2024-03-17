/*
problem : 0~9999의 숫자 중 특정 숫자에서 D, S, L, R 연산을 이용해 목표 숫자로 만드는 최소 연산 횟수를 구해라.
input : 초기 숫자, 목표 숫자
output : 목표 숫자를 만들기 위해 D, S, L, R 연산을 최소로 사용하는 횟수

idea
- root가 초기 숫자, node가 D, S, L, R 연산을 한 이후 연산 결과를 의미하는 tree로 만든다.
- tree를 BFS 방식으로 탐색한다.
- tree를 탐색할 때, 이미 탐색한 숫자라면 더 이상 탐색하지 않는다.
*/
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

bool Search[10000];                        // 해당 숫자를 탐색했는지 여부

void BFS(int Start, int End)
{
    queue<pair<int, string>> next;           // 다음에 탐색할 node
    int CurrentNumber;                       // 현재 숫자
    string CurrentOperators;                 // 현재까지 진행한 연산들
    int ComputeNumber;                       // 연산된 숫자

    // 시작점을 탐색 설정하고, queue에 넣는다.
    Search[Start] = true;
    next.push(make_pair(Start, ""));

    while (!next.empty())
    {
        CurrentNumber = next.front().first;
        CurrentOperators = next.front().second;
        next.pop();

        // 만약 목표 숫자에 도달했다면, 현재까지 진행한 연산들을 출력하고 탐색 중단
        if (CurrentNumber == End)
        {
            cout << CurrentOperators << '\n';
            return;
        }

        // 4가지 연산 진행
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