/*
2
2+3, 3
2+3+5, 3+5, 5
2+3+5+7, 3+5+7, 5+7, 7
2+3+5+7+11, 3+5+7+11, 5+7+11, 7+11, 11
2+3+5+7+11+13, 3+5+7+11+13, 5+7+11+13, 7+11+13, 11+13, 13

problem : 자연수 n을, 한 번 이상 연속되면서 중복되지 않게 소수를 사용하여 나타낼 수 있는 경우의 수를 구해라.
input : 자연수 n
output : 한 번 이상 연속되면서 중복되지 않게 소수를 사용하여 나타낼 수 있는 경우의 수

idea
- 자연수 n을 입력받고, 에라토스테네스의 체를 이용해 자연수 n이 넘어가기 전까지 소수들을 모두 구한다.
- root가 2, level이 더한 소수의 순번, node가 소수를 더한 후의 숫자를 나타내는 tree를 만든다.
- tree를 더한 소수가 자연수 n을 넘어가기 전까지 BFS 방식으로 탐색한다.
- non-promising 조건 : 더한 후의 숫자가 자연수 n을 넘어갈 때
*/
#include <iostream>
#include <queue>
#define BOUND 4000001
using namespace std;

typedef unsigned int uint;

bool IsNotPrimary[BOUND];                   // 각 숫자가 소수가 아닌지 여부
uint NumberOfCase[BOUND];                    // 각 숫자를 만들 수 있는 경우의 수
uint Input;                                  // 입력된 자연수 n

// promising 판별
bool Promising(uint _node)
{
    if (_node > Input)
        return false;
    return true;
}

// 소수 찾기
void FindPrimeNumber()
{
    // 1 제외
    IsNotPrimary[1] = true;

    // 2 ~ n까지의 범위 중 소수가 아닌 숫자는 제외
    for (uint i = 2; i * i <= Input; i++)
        if (!IsNotPrimary[i])
            for (uint j = i * i; j <= Input; j += i)
                IsNotPrimary[j] = true;
}

void BFS()
{
    queue<uint> search;                    // 다음에 탐색할 node들의 모음
    uint cur, next;                        // 현재 node, 다음 node
    uint Adder = 3;                        // 더할 숫자
    uint QueueSize;                        // 한 level에 있는 node의 개수(queue의 크기)

    // root를 queue에 넣고, root의 경우의 수를 1 증가
    search.push(2);
    NumberOfCase[2]++;

    // 탐색
    while (1)
    {
        // 더할 숫자를 소수로 만든다.
        while (Adder <= Input && IsNotPrimary[Adder])
            Adder += 2;

        // 더할 숫자가 자연수 n을 넘어가면 탐색 종료
        if (Adder > Input)
            return;

        // queue의 크기만큼 loop를 돌면서 소수를 더한 후 promising 검사
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

        // level 증가
        Adder += 2;
    }
}

int main()
{
    // 자연수 n 입력
    cin >> Input;

    // 자연수 n까지 범위 중 소수가 아닌 숫자는 제외
    FindPrimeNumber();

    // tree를 BFS 방식으로 탐색
    BFS();

    // 결과값 출력
    cout << NumberOfCase[Input];

    return 0;
}