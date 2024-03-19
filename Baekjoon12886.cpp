/*
problem : 서로 다른 3개의 숫자가 주어지고, 연산(이 중 2개(X, Y)를 골라 X+X, Y-X를 하는 것)으로 서로 같은 숫자가 되게 하려고 한다.
          서로 다른 3개의 숫자를 같게 만드는 방법을 구해라.
input : 서로 다른 3개의 숫자
output : 서로 다른 3개의 숫자를 같게 만드는 방법

idea
- 서로 다른 3개의 숫자 합이 3의 배수가 아니라면 0을 출력
- A <= B <= C 라고 가정
- root는 입력된 숫자, level을 연산을 한 횟수, node는 (A, B)를 선택한 경우 또는 (A, C)를 선택한 경우, (B, C)를 선택한 경우를 나타내는 tree를 만든다.
- tree를 BFS 방식으로 탐색한다.
- 각 node의 숫자는 연산 후에 오름차순으로 정렬한다.
- 연산된 결과가 이미 탐색한 node라면 더 탐색하지 않는다.
- 만약 고른 숫자 2개가 서로 같은 숫자라면 탐색하지 않는다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXIMUM 501
using namespace std;

int TotalSum = 0;                               // 숫자 3개의 합
bool Search[MAXIMUM][MAXIMUM];                // node 탐색 여부
                                              // 2개의 숫자와 총합을 이용하면 다른 숫자를 구할 수 있기 때문에 2개의 숫자만 이용

bool BFS(int _n1, int _n2);

int main()
{
    // 3개의 숫자 입력하고, 총합을 구한 후 오름차순으로 정렬
    int Input[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> Input[i];
        TotalSum += Input[i];
    }
    sort(Input, Input + 3);

    // BFS 탐색 결과 출력
    if (TotalSum % 3)
        cout << 0;
    else
        cout << BFS(Input[0], Input[1]);

    return 0;
}

bool BFS(int _n1, int _n2)
{
    queue<pair<int, int>> next;         // 다음에 탐색할 node들의 모음
    int Current[3];                     // 현재 node
    int Next[3];                        // 다음에 탐색할 node

    // root 탐색 여부를 설정하고 queue에 push
    Search[_n1][_n2] = true;
    next.push(make_pair(_n1, _n2));

    // 탐색
    while (!next.empty())
    {
        // queue에서 node를 하나 꺼내고 정렬
        Current[0] = next.front().first;
        Current[1] = next.front().second;
        Current[2] = TotalSum - Current[0] - Current[1];
        next.pop();

        sort(Current, Current + 3);

        // 만약 3개의 숫자가 모두 같다면 true를 return
        if (Current[0] == Current[1] && Current[0] == Current[2])
            return true;

        // 2개의 숫자를 골라 연산
        // (A, B)
        if (Current[0] != Current[1])
        {
            // 연산
            Next[0] = Current[0] * 2;
            Next[1] = Current[1] - Current[0];
            Next[2] = Current[2];

            // 정렬 후 검사
            sort(Next, Next + 3);
            if (!Search[Next[0]][Next[1]])
            {
                Search[Next[0]][Next[1]] = true;
                next.push(make_pair(Next[0], Next[1]));
            }
        }
        // (A, C)
        if (Current[0] != Current[2])
        {
            // 연산
            Next[0] = Current[0] * 2;
            Next[1] = Current[2] - Current[0];
            Next[2] = Current[1];

            // 정렬 후 검사
            sort(Next, Next + 3);
            if (!Search[Next[0]][Next[1]])
            {
                Search[Next[0]][Next[1]] = true;
                next.push(make_pair(Next[0], Next[1]));
            }
        }
        // (B, C)
        if (Current[1] != Current[2])
        {
            // 연산
            Next[0] = Current[1] * 2;
            Next[1] = Current[2] - Current[1];
            Next[2] = Current[0];

            // 정렬 후 검사
            sort(Next, Next + 3);
            if (!Search[Next[0]][Next[1]])
            {
                Search[Next[0]][Next[1]] = true;
                next.push(make_pair(Next[0], Next[1]));
            }
        }
    }

    // 방법을 찾지 못했으므로 false를 반환
    return false;
}