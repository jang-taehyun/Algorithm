/*
problem : n개의 회의가 주어질 때, 회의를 최대로 할 수 있는 경우를 구해라.
input : n개의 회의
output : 회의를 최대로 할 수 있는 경우

idea
- 입력된 값을 회의 끝나는 시간에 따라 오름차순으로 sort
- 첫 번째 회의의 끝나는 시간을 기준으로 다음 회의의 시작 시간이 기준보다 크다면,
  기준을 다음 회의의 끝나는 시간으로 update하고 다음 회의를 진행한다.(greedy)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<int, int>> Schedule;            // 회의 schedule
    int ScheduleCnt;                            // 회의 schedule의 개수
    int Start, End;                             // 회의의 시작 시간, 끝나는 시간
    int res = 1;                                // 최대로 할 수 있는 회의의 횟수

    // 회의 schedule 입력
    cin >> ScheduleCnt;
    for (int i = 0; i < ScheduleCnt; i++)
    {
        cin >> Start >> End;
        Schedule.push_back(make_pair(End, Start));
    }

    // 회의 schedule을 끝나는 시간을 기준으로 오름차순으로 정렬
    sort(Schedule.begin(), Schedule.begin() + ScheduleCnt);

    // greedy
    End = Schedule[0].first;
    for (int i = 1; i < ScheduleCnt; i++)
    {
        if (Schedule[i].second >= End)
        {
            res++;
            End = Schedule[i].first;
        }
    }

    // 결과값 출력
    cout << res;

    return 0;
}