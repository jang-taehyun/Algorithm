/*
problem : 한번 상담하는데 걸리는 시간과 상담 후 받는 금액이 주어질 때, n일 안으로 상담할 시에 받을 수 있는 최대 금액을 구해라.
input : 상담하는데 걸리는 시간 day, 상담을 끝낸 후 받는 금액 price, 상담할 수 있는 시간 period
output : n일 안으로 상담할 시에 받을 수 있는 최대 금액

idea : DFS 방식으로 n일이 넘어가지 않게 상담을 몇 건 고른 후, 받을 수 있는 금액을 계산한다.
만약 현재 탐색한 결과가 이전에 얻어진 최대 금액보다 클 경우, 최대 금액을 현재 탐색한 결과로 바꾼다.

- state space tree : level이 상담을 의미하고, left node가 상담을 고른 경우, right node가 상담을 고르지 않는 경우를 나타낸다.
예시)
                                      (start)
level1 == 1일차 상담        (1일차 고른다)    (1일차 고르지 않는다)
*/
#include <iostream>
using namespace std;

int day[16];        // 상담하는데 걸리는 시간 day
int price[16];      // 상담 후에 받는 금액 price
int period;         // 상담할 수 있는 기간 period
int result;         // n일 안으로 상담할 시에 받을 수 있는 최대 금액 result

void DFS(int currentDay, int currentSum)
{
    // n+1일이 넘어가면 탐색을 중단한다.
    if(currentDay > period+1)
        return;
    
    // n+1일에 이전에 얻었던 최대 금액과 현재 얻은 최대 금액을 비교한 후 탐색을 종료한다.
    // 비교 시 현재 얻은 최대 금액이 이전에 얻었던 최대 금액보다 클 경우, 결과값을 현재 얻은 최대 금액으로 업데이트 한다.
    if(currentDay == period+1)
    {
        result = currentSum > result ? currentSum : result;
        return;
    }
    
    // startDay부터 시작하여 DFS 방식으로 상담을 고른 후 받을 수 있는 금액을 계산한다.
    // 현재 탐색하고 있는 상담을 고를 경우
    DFS(currentDay+day[currentDay], currentSum+price[currentDay]);
    // 현재 탐색하고 있는 상담을 고르지 않을 경우
    DFS(currentDay+1, currentSum);
}

int main()
{
    // input 입력
    cin >> period;
    for(int i=1; i<=period; i++)
        cin >> day[i] >> price[i];
    
    // DFS 방식으로 상담을 고른 후 얻을 수 있는 최대 금액을 구한다.
    DFS(1, 0);
    
    // 얻을 수 있는 최대 금액을 출력한다.
    cout << result;
    
    return 0;
}
