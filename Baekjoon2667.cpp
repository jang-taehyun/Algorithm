/*
problem : n*n칸의 지도에 존재하는 단지의 개수와 단지 내 집 수를 오름차순으로 출력해라.
input : n*n칸의 지도
output : 단지의 개수, 단지 내 집의 수

idea
- DFS 방식으로 단지를 탐색하여 단지 내 집 수를 구한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Map[25][25];        // n*n칸의 지도
bool isVisited[25][25];  // 각 칸의 방문 여부 isVisited
int mapLength;           // 지도의 길이 mapLength == n
vector<int> houseNum;    // 단지 내 집 수
int currentCount;        // 탐색한 칸의 개수 currentCount

// 좌표 이동 경로 : 왼쪽부터 상, 하, 좌, 우
int deltX[4] = {-1, 1, 0, 0};
int deltY[4] = {0, 0, -1, 1};

// DFS 방식으로 지도를 탐색
void DFS(int x, int y)
{   
    // 현재 좌표 방문 표시 및 탐색한 칸 증가
    isVisited[x][y]=true;
    currentCount++;
    
    // 현재 좌표와 연결된 좌표를 DFS 방식으로 탐색
    for(int i=0; i<4; i++)
    {
        int next_x = x + deltX[i];
        int next_y = y + deltY[i];
        
        // 다음 좌표가 범위를 넘어가면 다른 좌표를 탐색
        if(next_x < 0 || next_x >= mapLength || next_y < 0 || next_y >= mapLength)
            continue;
        
        // 다음 좌표가 연결되어 있고 방문하지 않았다면 탐색
        if(Map[next_x][next_y] && !isVisited[next_x][next_y])
            DFS(next_x, next_y);
    } 
}

int main()
{
    int countryCount=0;            // 단지의 개수 countryCount
    string input;
    
    // input 입력
    cin >> mapLength;
    for(int i=0; i<mapLength; i++)
    {
        cin >> input;
        
        for(int j=0; j<input.length(); j++)
            Map[i][j] = input[j] == '1' ? true : false;
    }
        
    
    // DFS 방식으로 지도 탐색
    for(int i=0; i<mapLength; i++)
    {
        for(int j=0; j<mapLength; j++)
        {
            // 단지를 발견했다면
            if(!isVisited[i][j] && Map[i][j])
            {
                // 탐색한 칸 초기화
                currentCount=0;
                
                // 탐색 시작
                DFS(i, j);
                
                // 단지 내 집의 개수 저장 및 단지의 개수 증가
                houseNum.push_back(currentCount);
                countryCount++;
            }
        }
    }
    
    // 단지 내 집의 개수를 오름차순으로 정렬
    sort(houseNum.begin(), houseNum.end());
    
    // 결과 출력
    cout << countryCount << '\n';
    for(int i=0; i<countryCount; i++)
        cout << houseNum[i] << '\n';
    
    return 0;
}
