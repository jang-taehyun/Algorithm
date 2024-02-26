/*
problem : n 종류의 동전을 이용해 k원을 만드는 방법 중 동전을 최소로 쓰는 방법을 구해라.
input : n 종류의 동전, 만들고자 하는 액수 k
output : k원을 만드는 데 사용하는 최소 동전 개수

idea
- k원보다 작으면서 가장 큰 동전을 고르고, 그 금액을 뺀다
- 0원이 될 때까지 반복
*/
#include <iostream>
using namespace std;

int main()
{
    int coinNum;        // 동전 종류의 개수 coinNum
    int target;         // 목표 금액 target
    int price[10];      // 각 동전의 금액 price
    
    // input 입력
    cin >> coinNum >> target;
    for(int i=0; i<coinNum; i++)
        cin >> price[i];
    
    int res=0;                        // 동전의 개수 res
    int currentIdx=coinNum-1;         // 현재 탐색하는 동전의 종류 currentIdx
    // 목표 금액이 0이 될 때까지 반복
    while(target)
    {
        // 현재 동전의 가치가 목표 금액보다 높으면 그 다음으로 가치가 높은 동전 탐색
        if(target < price[currentIdx])
        {
            currentIdx--;
            continue;
        }
        
        // 목표 금액에서 현재 동전의 가치를 빼고, 동전의 개수 증가
        target -= price[currentIdx];
        res++;
    }
    
    // 결과 출력
    cout << res;
    
    return 0;
}
