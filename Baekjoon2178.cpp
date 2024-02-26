/*
problem : n*m 칸의 지도에서 (0, 0)부터 시작해 (n-1, m-1)로 가는 방법 중 지나야되는 칸의 수를 최소로 하는 방법을 구해라.
input : n*m 칸의 지도
output : 지나야되는 칸의 최소 수

idea : n*m 칸의 지도를 BFS 방식으로 탐색하면서 방문 순서를 저장한다.
이때 방문 순서가 지나야되는 칸의 최소 수가 된다.
*/
#include <iostream>
#include <queue>
using namespace std;

bool Map[100][100];            // n*m 칸의 지도
int row, column;               // 지도의 가로, 세로 row, column == n, m
bool isVisited[100][100];      // 칸의 방문 여부 isVisited

// 칸의 이동 경로 : 왼쪽부터 상, 하, 좌, 우
int deltX[4] = {-1, 1, 0, 0};
int deltY[4] = {0, 0, -1, 1};

int searchSeq[100][100];       // 방문 순서 searchSeq

void BFS(int x, int y)
{   
    // 현재 좌표 방문 표시 및 방문 순서 저장
    isVisited[x][y] = true;
    searchSeq[x][y] = 1;
    
    // 큐 생성 및 시작점 push
    queue<pair<int, int>> nextSearch;
    nextSearch.push(make_pair(x, y));
    
    while(!nextSearch.empty())
    {
        // queue에서 데이터 pop
        int current_x = nextSearch.front().first;
        int current_y = nextSearch.front().second;
        nextSearch.pop();
        
        // 인접한 칸 중 연결된 칸을 모두 방문
        for(int i=0; i<4; i++)
        {
            int next_x = current_x + deltX[i];
            int next_y = current_y + deltY[i];
            
            // 지도의 범위를 넘어간다면 다른 칸 탐색
            if(next_x < 0 || next_y < 0 || next_x >= column || next_y >= row)
                continue;
            
            // 아직 방문하지 않고 연결된 칸을 queue에 push
            if(Map[next_x][next_y] && !isVisited[next_x][next_y])
            {
                // 방문 처리 및 방문 순서 저장
                isVisited[next_x][next_y] = true;
                searchSeq[next_x][next_y] = searchSeq[current_x][current_y]+1;
                
                // queue에 push
                nextSearch.push(make_pair(next_x, next_y));
            }
        }
    }
}

int main()
{
    // input 입력
    cin >> column >> row;
    string input;
    for(int i=0; i<column; i++)
    {
        cin >> input;
        
        for(int j=0; j<input.length(); j++)
            Map[i][j] = input[j] - '0';
    }
    
    // 탐색 시작
    BFS(0, 0);
    
    // 결과 출력
    cout << searchSeq[column-1][row-1];
    
    return 0;
}
