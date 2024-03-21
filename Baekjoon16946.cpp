/*
problem : n*m board에 있는 벽이 있는 칸에서, 각 벽을 부수고 이동할 수 있는 칸의 개수를 구해라.
input : n*m board
output : 각 벽이 있는 칸에서부터 시작해 이동할 수 있는 칸의 개수

idea
- board의 서로 연결된 빈칸(0인 칸)에 BFS 방식으로 번호를 붙이고, vector에 빈 칸의 개수를 저장
- 벽(1인 칸)에서 상하좌우를 탐색해 저장된 빈칸의 개수를 더한다.

참고 자료 : https://yabmoons.tistory.com/216
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 1000
#define INIT 2
using namespace std;

int Column, Row;                        // board의 column, row
int Board[MAX][MAX];                    // board
int CopyBoard[MAX][MAX];                // 복사된 board(정답 출력용)
vector<int> EmptySpace;                 // board에서 서로 연결된 빈칸의 개수
                                        // index : 빈 칸의 번호
int EmptySpaceCount = INIT;               // 빈칸 번호의 개수
int dx[4] = { 0, 0, 1, -1 };              // 이동 방향
int dy[4] = { -1, 1, 0, 0 };

// 범위, 탐색 여부 검사
bool IsPromising(int x, int y);

// 범위 검사
bool IsRange(int x, int y);

// 현재 칸과 연결된 빈칸 탐색
void FindEmptySpace(int sx, int sy);

int main()
{
    string input;
    int cx, cy, nx, ny;
    bool IsSearch = false;
    vector<int> SearchEmptySpaceNumber;     // 이미 탐색한 빈칸의 숫자들
    vector<pair<int, int>> Wall;            // 벽의 위치들

    // board 정보 입력 및 벽들의 위치를 vector에 저장
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;

        for (int j = 0; j < Row; j++)
        {
            Board[i][j] = input[j] - '0';
            CopyBoard[i][j] = Board[i][j];
            if (Board[i][j])
                Wall.push_back(make_pair(i, j));
        }
    }

    // 서로 연결된 빈칸에 번호를 붙인다.
    for (int i = 0; i < Column; i++)
        for (int j = 0; j < Row; j++)
            if (!Board[i][j])
                FindEmptySpace(i, j);

    // 벽들의 위치에서 상하좌우를 탐색해 연결된 빈 칸의 개수를 구한다.
    for (int i = 0; i < Wall.size(); i++)
    {
        cx = Wall[i].first;
        cy = Wall[i].second;

        for (int dir = 0; dir < 4; dir++)
        {
            nx = cx + dx[dir];
            ny = cy + dy[dir];

            // 범위 검사
            if (!IsRange(nx, ny))
                continue;
            // 벽 검사
            if (CopyBoard[nx][ny] == 1)
                continue;
            // 해당 빈칸 번호를 이미 탐색했는지 검사
            IsSearch = false;
            for (int j = 0; j < SearchEmptySpaceNumber.size(); j++)
            {
                if (SearchEmptySpaceNumber[j] == Board[nx][ny])
                {
                    IsSearch = true;
                    break;
                }
            }
            if (IsSearch)
                continue;

            // 검사를 모두 통과했다면, 빈 칸의 개수를 더하고 탐색 설정
            SearchEmptySpaceNumber.push_back(Board[nx][ny]);
            CopyBoard[cx][cy] = (CopyBoard[cx][cy] + EmptySpace[Board[nx][ny] - INIT]) % 10;
        }

        SearchEmptySpaceNumber.clear();
    }

    // 결과값 출력
    for (int i = 0; i < Column; i++)
    {
        for (int j = 0; j < Row; j++)
            cout << CopyBoard[i][j];
        cout << '\n';
    }

    return 0;
}

bool IsRange(int x, int y)
{
    if (x < 0 || x >= Column || y < 0 || y >= Row)
        return false;
    return true;
}

bool IsPromising(int x, int y)
{
    if (!IsRange(x, y))
        return false;
    if (Board[x][y])
        return false;

    return true;
}

void FindEmptySpace(int sx, int sy)
{
    queue<pair<int, int>> next;            // 다음에 탐색할 칸들
    int cx, cy, nx, ny;                    // 현재 위치, 다음 위치
    int cnt = 1;                             // 빈 칸의 개수

    // 시작점을 탐색 설정하고 queue에 push
    Board[sx][sy] = EmptySpaceCount;
    next.push(make_pair(sx, sy));

    // BFS 방식으로 탐색
    while (!next.empty())
    {
        cx = next.front().first;
        cy = next.front().second;
        next.pop();

        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (IsPromising(nx, ny))
            {
                Board[nx][ny] = EmptySpaceCount;
                next.push(make_pair(nx, ny));
                cnt++;
            }
        }
    }

    // 빈 칸의 개수를 vector에 넣고, 빈칸 번호 증가
    EmptySpace.push_back(cnt);
    EmptySpaceCount++;
}