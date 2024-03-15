/*
problem : 10*10 board에서 1~100까지 번호가 메겨져 있고, 특정 번호에 도착할 때 다른 번호로 이동할 수 있을 때, 1번 부터 시작하여 100번째 칸에 도착할 때까지 주사위를 굴리는 최소 횟수를 구해라.
input : 특정 번호에 도착했을 때 이동하는 번호
output : 100번째 칸에 도착할 때까지 굴리는 주사위의 최소 횟수

idea
- level은 주사위를 굴리는 횟수, node는 주사위의 눈이 1~6나올 때 도착하는 번호를 나타내는 tree를 만든다.
- tree를 BFS 방식으로 탐색한다.
- 탐색하면서 특정 번호에 도착했을 때 이동하는 번호가 있다면, 그 번호로 이동한다.
- 이전에 탐색한 칸이라면 더 탐색하지 않는다.(탐색이 중복되기 때문)
*/
#include <iostream>
#include <queue>
#define START 1
#define END 100
using namespace std;

int MoveNumber[END];                // index번째 칸에 도착했을 때 이동하는 칸
                                    // 0이라면 이동하지 않는다.
const int Length = END + 7;           // 방문 여부의 길이
bool visited[Length];               // 각 칸의 방문 여부

int BFS()
{
    queue<int> next;                // 다음으로 탐색할 node
    int QueueSize;                  // queue의 크기
    int CurrentNode, NextNode;      // 현재 탐색하고 있는 node, 다음으로 탐색할 node
    int CurrentLevel = 0;             // 현재 탐색하고 있는 level

    // 시작점을 방문 표시하고 queue에 넣는다.
    visited[START] = true;
    next.push(START);

    while (!next.empty())
    {
        // queue의 크기 만큼 반복
        QueueSize = next.size();
        for (int i = 0; i < QueueSize; i++)
        {
            // queue에서 탐색할 node를 하나 꺼낸다.
            CurrentNode = next.front();
            next.pop();

            // 100번째 칸에 도착하거나 100이 넘는다면, level(주사위를 굴린 횟수)를 return
            if (CurrentNode >= END)
                return CurrentLevel;

            // 6가지 경우 중 아직 탐색하지 않는 칸을 queue에 넣는다.
            for (int j = 1; j <= 6; j++)
            {
                NextNode = CurrentNode + j;
                if (!visited[NextNode])
                {
                    visited[NextNode] = true;

                    // 만약 특정 칸으로 이동할 수 있다면, 특정 칸으로 이동
                    if (MoveNumber[NextNode])
                    {
                        NextNode = MoveNumber[NextNode];
                        visited[NextNode] = true;
                    }

                    // queue에 넣는다.
                    next.push(NextNode);
                }
            }
        }

        // level 증가
        CurrentLevel++;
    }
}

int main()
{
    int Special1, Special2;
    int Source, Destination;

    // 다른 칸으로 이동할 수 있는 특정 칸 입력
    cin >> Special1 >> Special2;
    for (int i = 0; i < Special1 + Special2; i++)
    {
        cin >> Source >> Destination;
        MoveNumber[Source] = Destination;
    }

    // BFS를 통해 탐색해 주사위를 굴리는 최소 횟수를 구한다.
    cout << BFS();

    return 0;
}