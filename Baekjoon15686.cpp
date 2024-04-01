/*
problem : n*n board에서 2로 채워진 칸이 a개 있고, 1로 채워진 칸이 b개가 있다.
          칸 사이의 거리를 (|x1-x2| + |y1-y2|)로 계산할 때,
          2로 채워진 칸 a개 칸 중 m개를 골라 (|x1-x2| + |y1-y2|)의 합의 최소값을 구해라.
input : n*n board, 고르는 개수 m
output : 2로 채워진 칸 a개 칸 중 m개를 골라 (|x1-x2| + |y1-y2|)의 합의 최소값

idea
- 2로 채워진 칸을 vector에 넣는다.
- DFS 방식을 통해 2로 채워진 칸 중 m개를 고르고, (|x1-x2| + |y1-y2|)의 합을 구한다.
- 현재까지 구해진 합과 현재 구해진 값을 비교해 update
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int BoardLength;                  // board의 한 변의 길이
int Board[50][50];                // board
int ChooseCount;                  // 고를 개수
vector<pair<int, int>> Two;       // 2로 채워진 칸들의 모임
vector<pair<int, int>> One;       // 1로 채워진 칸들의 모임
bool visited_Two[14];             // 2로 채워진 칸들 중 방문 여부
int res = 99999999;               // 결과값

void DFS(int cnt, int start)
{
    // m개를 모두 골랐다면, (|x1-x2| + |y1-y2|)의 합을 구한다.
    if (cnt >= ChooseCount)
    {
        int ComputeSum = 0;
        int tmp1, tmp2;
        int cx, cy;

        for (int i = 0; i < One.size(); i++)
        {
            tmp1 = 99999999;
            for (int j = 0; j < Two.size(); j++)
            {
                // 고르지 않는 칸은 연산에서 제외
                if (!visited_Two[j])
                    continue;

                // 1인 칸을 기준으로 고른 2인 칸들 중 (|x1-x2| + |y1-y2|)이 가장 작은 값을 선택
                tmp2 = abs(One[i].first - Two[j].first) + abs(One[i].second - Two[j].second);
                tmp1 = min(tmp1, tmp2);
            }

            // 최소값을 골랐다면, 누적해서 더한다.
            ComputeSum += tmp1;
        }

        // 이전에 구한 값과 현재 구한 값을 비교해 update
        res = min(res, ComputeSum);

        return;
    }

    // m개의 위치를 고른다.
    for (int i = start; i < Two.size(); i++)
    {
        if (visited_Two[i])
            continue;

        visited_Two[i] = true;
        DFS(cnt + 1, i + 1);
        visited_Two[i] = false;
    }
}

int main()
{
    // n*n board, 고를 개수 입력
    cin >> BoardLength >> ChooseCount;
    for (int i = 0; i < BoardLength; i++)
    {
        for (int j = 0; j < BoardLength; j++)
        {
            cin >> Board[i][j];

            if (Board[i][j] == 1)
                One.push_back(make_pair(i, j));
            else if (Board[i][j] == 2)
                Two.push_back(make_pair(i, j));
        }
    }

    // 2인 칸들 중 m개를 골라 (|x1-x2| + |y1-y2|)의 합의 최소값을 구한다.
    DFS(0, 0);

    // 결과값 출력
    cout << res;

    return 0;
}