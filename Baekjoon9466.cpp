/*
problem : 배열 S 안에 각 index가 선택한 숫자가 존재할 때, 선택되지 못해 그룹에 속하지 않는 숫자의 개수를 구해라.
input : 배열 S
output : 선택되지 못해 그룹에 속하지 않는 숫자의 개수

idea
- root가 index, level이 탐색한 횟수, node가 다음에 탐색할 index를 의미하는 tree를 만든다.
- tree를 DFS 방식으로 탐색한다.
- non-promising 조건
  - 이미 탐색을 완료해 재방문할 일이 없는 node를 탐색하려는 경우
  - 이미 탐색한 index를 다시 탐색할 때, 재방문 여부가 남아있는 경우 -> Cycle 형성
- 각 index마다 tree를 DFS 방식으로 탐색하면서, cycle을 발견하면 전체 개수에서 cycle에 있는 요소의 개수를 뺀다.

참고 자료 : https://jaimemin.tistory.com/674
*/
#include <iostream>
#include <cstring>
using namespace std;

int Tree[100000];                    // tree
bool IsSearch[100000];               // 해당 node 방문 여부
bool IsSearchDone[100000];           // 해당 node를 더 탐색할지 말지 여부
int res = 100000;

void DFS(int cur)
{
    // 현재 node가 이미 탐색했는지 확인
    if (!IsSearch[cur])
    {
        IsSearch[cur] = true;
        DFS(Tree[cur]);
    }
    // 현재 node를 재방문 했지만 다시 방문할 여지가 있다면,
    // 현재 node가 나올 때까지 tree를 역순으로 탐색해 cycle에 넣는다.
    else if (IsSearch[cur] && !IsSearchDone[cur])
    {
        // index가 현재 node가 될 때까지 그룹으로 편입
        int idx = cur;
        int minus = 0;
        do
        {
            IsSearchDone[idx] = true;
            idx = Tree[idx];
            minus++;
        } while (idx != cur);

        // 전체 개수에서 그룹에 속한 인원 제외
        res -= minus;

        // 탐색 종료
        return;
    }

    // 재방문 여부 설정
    IsSearchDone[cur] = true;
}

int main()
{
    // test 횟수 입력
    int test, len, tmp;
    cin >> test;

    while (test--)
    {
        // 초기화
        memset(IsSearchDone, 0, sizeof(IsSearchDone));
        memset(IsSearch, 0, sizeof(IsSearch));
        memset(Tree, 0, sizeof(Tree));

        // 배열 S 입력
        cin >> len;
        for (int i = 0; i < len; i++)
        {
            cin >> tmp;
            Tree[i] = tmp - 1;
        }

        // BFS 탐색
        res = len;
        for (int i = 0; i < len; i++)
            DFS(i);

        // 결과값 출력
        cout << res << '\n';
    }

    return 0;
}