/*
problem : k*k board에서 (n, m)칸에 있는 데스나이트를 (x, y)로 이동할 때, 데스나이트의 최소 이동 횟수를 구해라.
input : 시작점(n, m), 도착점(x, y), board의 크기(k)
output : (n, m)에서 시작해 (x, y)에 도착하는 최소 이동 횟수

idea
- (n, m)가 root이고, level이 이동 횟수, node가 움직인 후 결과를 나타내는 tree를 만든다.
- tree를 BFS 방식으로 탐색한다.
- 만약 이전에 탐색한 칸이라면 더 이상 탐색하지 않는다.
- (x, y)에 도착하면 level을 return
*/
#include <iostream>
#include <queue>
using namespace std;

bool Search[200][200];                // 해당 칸을 탐색했는지 여부
int BoardLength;                      // board의 한 변의 길이
int dx[6] = { -2, -2, 0, 0, 2, 2 };     // 이동 방향
int dy[6] = { -1, 1, -2, 2, -1, 1 };

int BFS(int sx, int sy, int ex, int ey)
{
    queue<pair<int, int>> next;       // 다음에 탐색할 칸
    int QueueSize;                    // queue의 크기
    int MoveCount = 0;                  // 움직인 횟수
    int CurX, CurY, NextX, NextY;     // 현재 탐색하고 있는 칸, 다음에 탐색할 칸

    // 시작점을 탐색 표시하고 queue에 넣는다.
    Search[sx][sy] = true;
    next.push(make_pair(sx, sy));

    while (!next.empty())
    {
        // queue의 크기만큼 반복
        QueueSize = next.size();
        for (int i = 0; i < QueueSize; i++)
        {
            // queue에서 좌표 하나를 꺼내서 탐색
            CurX = next.front().first;
            CurY = next.front().second;
            next.pop();

            // 도착점에 도착했다면 현재 level return
            if (CurX == ex && CurY == ey)
                return MoveCount;

            // 이동할 칸 중 아직 탐색하지 않는 칸을 queue에 넣는다.
            for (int j = 0; j < 6; j++)
            {
                NextX = CurX + dx[j];
                NextY = CurY + dy[j];

                // 범위 및 탐색 여부 검사
                if (NextX < 0 || NextX >= BoardLength || NextY < 0 || NextY >= BoardLength)
                    continue;
                if (Search[NextX][NextY])
                    continue;

                Search[NextX][NextY] = true;
                next.push(make_pair(NextX, NextY));
            }
        }

        // 한 level을 모두 탐색했으므로 level 증가 
        MoveCount++;
    }

    // 이동할 수 없다면 -1을 return
    return -1;
}

int main()
{
    int sx, sy, ex, ey;

    // board의 한 변의 길이 및 시작점, 도착점 입력
    cin >> BoardLength;
    cin >> sx >> sy >> ex >> ey;

    // tree를 BFS 방식으로 탐색해 최소 이동 횟수를 구한다.
    cout << BFS(sx, sy, ex, ey);

    return 0;
}