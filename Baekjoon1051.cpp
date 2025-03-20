#include <iostream>
using namespace std;

int main()
{
    int c, r;                    // board의 세로, 가로 길이
    int board[50][50] = {0, };   // board
    char input;                  // 입력
    int dy[3] = {0, 1, 1};       // 정사각형의 꼭지점
    int dx[3] = {1, 1, 0};
    int ny, nx;                  // 다음에 탐색할 정사각형의 꼭지점
    int maxLen = 1;              // 정사각형이 가질 수 있는 최대 길이
    bool IsRectangle = true;     // 정사각형이 만들어지면서, 정사각형의 꼭짓점이 모두 같은 수 인지 판단
    int rec_size = 1;            // 정사각형의 크기
    int res = 1;
    
    // 입력
    cin >> c >> r;
    for(int i=0; i<c; ++i)
        for(int j=0; j<r; ++j)
        {
            cin >> input;
            board[i][j] = input - '0';
        }
    
    // 정사각형이 가질 수 있는 최대 길이 구하기
    maxLen = (c > r ? c : r);
    
    // board의 각 요소 탐색
    for(int i=0; i<c; ++i)
    {
        for(int j=0; j<r; ++j)
        {
            // 정사각형이 가질 수 있는 최대 길이만큼 반복
            for(int l=1; l<maxLen; ++l)
            {
                IsRectangle = true;
                
                for(int k=0; k<3; ++k)
                {
                    ny = i + (l * dy[k]);
                    nx = j + (l * dx[k]);
                    
                    // 다음 꼭지점의 범위 계산
                    if(ny < 0 || ny >= c || nx < 0 || nx >= r)
                    {
                        IsRectangle = false;
                        break;
                    }
                    // 정사각형의 모든 꼭지점이 모두 같은 수를 가지고 있는지 계산
                    if(board[i][j] != board[ny][nx])
                    {
                        IsRectangle = false;
                        break;
                    }
                }
                
                // 만약 정사각형의 모든 꼭지점이 모두 같은 수를 가지고 있다면 정사각형의 최대 크기 갱신
                if(IsRectangle)
                {
                    rec_size = (l+1) * (l+1);
                    res = (res < rec_size ? rec_size : res);
                }
            }
        }
    }
    
    // 결과 출력
    cout << res;
    
    return 0;
}
