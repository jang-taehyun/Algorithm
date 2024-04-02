/*
problem : k개의 숫자가 queue에 있을 때, index가 n인 숫자가 queue에서 몇 번째로 빠져나가는지 구해라.
input : k개의 숫자, 구하고자 하는 숫자의 위치 n
output : index가 n인 숫자가 queue에서 몇 번째로 빠져나가는지

idea
- 각 테스트케이스마다 queue를 초기화한다.
- queue의 front를 push 또는 pop하여 index가 n인 숫자가 queue에서 몇 번째로 빠져나가는지 구한다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    queue<pair<int, bool>> q;            // k개의 숫자가 들어간 queue
                                         // first : 숫자, bool : 찾고자하는 위치인지
    vector<int> s;                       // 빼고자 하는 찾고자하는 우선순위
    int QueueSize, TargetIndex;          // queue의 크기, 찾고자하는 위치
    int test;                            // test 횟수
    int res = 0;                           // 결과값
    int idx = 0;                           // vector의 index

    int tmp1;
    bool tmp2;

    cin >> test;
    while (test--)
    {
        // input 입력
        cin >> QueueSize >> TargetIndex;
        for (int i = 0; i < QueueSize; i++)
        {
            cin >> tmp1;

            if (i == TargetIndex)
                q.push(make_pair(tmp1, true));
            else
                q.push(make_pair(tmp1, false));

            s.push_back(tmp1);
        }

        // vector를 오름차순으로 sort
        sort(s.begin(), s.end(), greater<int>());

        // 연산
        while (!q.empty())
        {
            tmp1 = q.front().first;
            tmp2 = q.front().second;
            q.pop();

            // 빼고자하는 우선순위인지 확인
            if (s[idx] == tmp1)
            {
                res++;
                idx++;

                // 찾고자 하는 위치를 찾았다면 뺸 횟수를 출력 후 loop 종료
                if (tmp2)
                {
                    cout << res << '\n';
                    break;
                }
            }
            else
            {
                q.push(make_pair(tmp1, tmp2));
            }
        }

        // 초기화
        while (!q.empty())
            q.pop();
        s.clear();
        res = 0;
        idx = 0;
    }

    return 0;
}