/*
problem : n*m board의 각 칸마다 알파벳 대문자가 있을때, (1, 1)에서부터 시작하여 서로 다른 알파벳을 지나면서 이동할 수 있는 칸의 최대 개수
input : n*m board의 정보
output : (1, 1)부터 시작해 서로 다른 알파벳을 지나면서 이동할 수 있는 칸의 최대 개수

idea
- (1, 1)에서부터 시작해 DFS 방식으로 탐색한다.
- 탐색할 때마다 최대값을 update
- 만약 이미 지나간 칸에 도착하는 경우, 탐색 종료
- 만약 더이상 이동할 수 없는 경우, 탐색 종료
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int Column, Row;            // board의 세로, 가로 길이
char Board[20][20];         // board의 각 칸에 쓰여진 알파벳 대문자
bool visited[20][20];       // board의 각 칸의 방문 여부
bool IsPass[26];            // 알파벳을 지나갔는지 여부

int dx[4] = { 0, 0, -1, 1 };  // 이동할 수 있는 방향
int dy[4] = { -1, 1, 0, 0 };

int MaximumPassLength = 1;    // 지나갈 수 있는 칸의 최대 개수

void DFS(int cx, int cy, int count)
{
    // 최대값 update
    MaximumPassLength = max(MaximumPassLength, count);

    // 4방향 중 하나를 선택해 이동한다.
    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        nx = cx + dx[i];
        ny = cy + dy[i];

        // 범위, 방문 여부, 이미 지난 알파벳인지 검사
        if (nx < 0 || nx >= Column || ny < 0 || ny >= Row)
            continue;
        if (visited[nx][ny])
            continue;
        if (IsPass[Board[nx][ny] - 'A'])
            continue;

        // 해당 칸에 이동
        visited[nx][ny] = true;
        IsPass[Board[nx][ny] - 'A'] = true;
        DFS(nx, ny, count + 1);

        // 원상복구
        visited[nx][ny] = false;
        IsPass[Board[nx][ny] - 'A'] = false;
    }
}

int main()
{
    string input;
    int nx, ny;

    // board의 정보 입력
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;
        for (int j = 0; j < Row; j++)
            Board[i][j] = input[j];
    }

    // (1, 1)부터 시작해 DFS 방식으로 board를 탐색하여 최대값을 구한다.
    visited[0][0] = true;
    IsPass[Board[0][0] - 'A'] = true;
    DFS(0, 0, 1);

    // 결과값 출력
    cout << MaximumPassLength;

    return 0;
}